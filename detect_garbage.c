/* detect_garbage.c
 * Hannah Soria
 * 5/2/2024
 * Identify garbage heap chunks using the mark-and-sweep method
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10
#define MAX_HEAP_SIZE 10

// A chunk on the heap could refer to other chunks on the heap
// the "marked" field is for use by the mark and sweep algorithm and
// isn't part of the data the code accesses.
typedef struct _HeapChunk {
    int num_references;
    int marked;
    struct _HeapChunk **references;
} HeapChunk;


// Var on stack. Can have value that is a reference to the Heap, or it could
// have a different value.
// We indicate its value is on heap by having reference by non-null
typedef struct {
    char *name;
    HeapChunk *reference;
} Var;

// Program state has stack and heap separately both stored as array for
// simplicity
typedef struct {
    Var *stack;  // array of all current variables
    int num_vars_on_stack;

    // array of all allocated HeapChunks (so array of pointers)
    HeapChunk **heap;
    int num_heap_chunks;
} ProgramState;

// make a new program state
ProgramState *createProgramState() {
    ProgramState *state = (ProgramState *)malloc(sizeof(ProgramState));
    state->stack = (Var *)malloc(sizeof(Var) * MAX_STACK_SIZE);
    state->heap = (HeapChunk **)malloc(sizeof(HeapChunk *) * MAX_HEAP_SIZE);
    state->num_heap_chunks = 0;
    state->num_vars_on_stack = 0;
    return state;
}

// allocate a chunk and return the address to it,
// but also add it to our list of allocated chunks on heap
HeapChunk *HeapMalloc(ProgramState *state) {
    HeapChunk *chunk = (HeapChunk *)malloc(sizeof(HeapChunk));
    chunk->num_references = 0;
    chunk->references = NULL;
    state->heap[state->num_heap_chunks] = chunk;
    state->num_heap_chunks++;
    return chunk;
}

// update the stack (either add name/value pair or update value)
void setVar(ProgramState *state, char *var_name, HeapChunk *chunk) {
    int found = 0;
    for (int i = 0; i < state->num_vars_on_stack; i++) {
        if (strcmp(state->stack[i].name, var_name) == 0) {
            found = 1;
            state->stack[i].reference = chunk;
        }
    }
    if (!found) {
        state->stack[state->num_vars_on_stack].name = strdup(var_name);
        state->stack[state->num_vars_on_stack].reference = chunk;
        state->num_vars_on_stack++;
    }
}

// adds a reference from chunk_source to chunk_target.
// method is humorously badly written, don't try to do this for too many
// references.
void addReference(HeapChunk *chunk_source, HeapChunk *chunk_target) {
    if (chunk_source->num_references++ == 0)
        chunk_source->references = malloc(sizeof(HeapChunk *));
    else
        chunk_source->references =
            realloc(chunk_source->references,
                       chunk_source->num_references * sizeof(HeapChunk *));
    chunk_source->references[chunk_source->num_references - 1] = chunk_target;
}

// Mark and Sweep, but don't really sweep - just report which chunks are garbage.
// First, you should unmark all the heap chunks by setting the mark value to 0. 
// You need to use the heap chunk array to access all heap chunks
// Then, you should trace through all heap chunks you can find from the stack.
// You need to use the stack and then implement a depth first search that follows
// all references (even from HeapChunk to HeapChunk).  Be sure not to get
// caught in any circular references (i.e. think about your stopping conditions).
// Finally, you should loop through the heap array again, this time reporting for each
// HeapChunk whether it is reachable or garbage.
void markAndSweep(ProgramState *state) {
    //set all values to 0
    for(int i = 0; i < state->num_heap_chunks;i ++){ // go through all of the heap chunks 
        state->heap[i]->marked = 0; // mark each one as 0
    }

    // stack to track the DFS
    HeapChunk ** visited_stack = (HeapChunk **)malloc(sizeof(HeapChunk *) * MAX_HEAP_SIZE); // stack to track which chunks have been visited

    // search all the heap chunks from the stack
    for(int i = 0; i< state->num_vars_on_stack; i++){ // iterate through the entire stack
        HeapChunk * chunk_ptr = state->stack[i].reference; // pointer to a heap chunk from the stack
        if(chunk_ptr != NULL && !chunk_ptr->marked){ // if the ptr is not null and not marked (hasn't been visited and exists)
            int top = -1; // the top of the stack, -1 because empty
            visited_stack[++top] = chunk_ptr; // push the current chunk onto the stack

            // go to each stack item and follow the references using DFS
            while(top >= 0) { //while there is something in the stack
                HeapChunk * curr_stack_ele = visited_stack[top--]; //pop the top chunk off and make it the current variable
                curr_stack_ele->marked = 1; // marked because it has been visited

                for(int j = 0;j < curr_stack_ele->num_references; j++){ // loop through all of the references for the current stack element
                    HeapChunk * curr_heap_ref = curr_stack_ele->references[j]; // current reference
                    if(curr_heap_ref != NULL && !curr_heap_ref->marked){ // if the current reference exists and has not been marked
                        visited_stack[++top] = curr_heap_ref; // add the current reference to the top of the stack
                    }
                }
            }
        }
    }

    // print out the results
    for(int i=0; i < state->num_heap_chunks; i++){ // iterate through all of the heap chunks
        HeapChunk * curr_chunk = state->heap[i]; // get the current heap chunk
        if(curr_chunk->marked){ // if marked = 1
            printf("heap chunk %p is reachable\n", (void *)curr_chunk); // reachable!
        } else {
            printf("heap chunk %p is garbage\n", (void *)curr_chunk); // garbage
        }
    }
    free(visited_stack); // free the memory
}


int main() {
    // Create the initial state
    ProgramState *state = createProgramState();

    //  simulate this simple example.
    // a = malloc()
    // b = malloc()
    // a = b;
    // HeapChunk *aChunk = HeapMalloc(state);
    // setVar(state, "a", aChunk);  // a = malloc()  (Drawing 1)
    // HeapChunk *bChunk = HeapMalloc(state);
    // setVar(state, "b", bChunk);    // b = malloc() (Drawing 2)
    // setVar(state, "a", bChunk);    // a = b (Drawing 3)

    // simulation an example that includes pointers in a cycle
    // a = malloc();
    // b = malloc();
    // a->b = b;
    // c = malloc();
    // b = malloc();
    // // c = b;
    // HeapChunk *aChunk = HeapMalloc(state);
    // setVar(state, "a", aChunk);  // a = malloc().
    // HeapChunk *bChunk = HeapMalloc(state);
    // setVar(state, "b", bChunk);    // b = malloc()
    // addReference(aChunk, bChunk);  // a->ref = b
    // addReference(bChunk, aChunk); // b->ref = a
    // // the above line will make your GC loop infinitely if you're not careful!
    // HeapChunk *cChunk = HeapMalloc(state);
    // setVar(state, "c", cChunk);  // c = malloc()
    // bChunk = HeapMalloc(state);
    // setVar(state, "b", bChunk);  // b = malloc()
    // setVar(state, "c", bChunk);

    // Identify the garbage    
    // markAndSweep(state); // (Drawing 5)

    // my own example
    HeapChunk *aChunk = HeapMalloc(state);
    setVar(state, "a", aChunk);  // a = malloc().
    HeapChunk *bChunk = HeapMalloc(state);
    setVar(state, "b", bChunk);    // b = malloc()
    HeapChunk *cChunk = HeapMalloc(state);
    setVar(state, "c", cChunk);  // c = malloc()
    addReference(aChunk, cChunk);  // a->ref = c
    setVar(state, "c", bChunk); // c->b
    addReference(cChunk, aChunk);  // c->ref = a
    HeapChunk *dChunk = HeapMalloc(state);
    setVar(state, "d", dChunk);  // d = malloc()
    setVar(state, "a", dChunk); // a->d



    //
    
    // Identify the garbage    
    markAndSweep(state); // (Drawing 5)

}
