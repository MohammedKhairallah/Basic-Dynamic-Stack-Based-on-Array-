/* 
 * File:   StackArrayDS.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 27, 2023, 8:01 PM
 */
#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H
/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */


/* Section : Data type Declarations */

/**
 * @brief Enum defining the status codes for stack operations
 */
typedef enum{
    STACK_NOK = 0,     /* Stack operation not performed successfully */
    STACK_OK,          /* Stack operation performed successfully  */
    STACK_FULL,        /* Stack is full */
    STACK_EMPTY,       /* Stack is empty */
    STACK_NULL_POINTER /* NULL pointer passed to the Stack operations */
}StackStatus_t;

/**
 * @brief Structure representing a stack
 */
typedef struct{
    void **StackArray;    /* Points to the array that allocated in the heap */
    sint32_t ElementCount;  /* Has the actual number of elements in the stack */
    uint32_t StackMaxSize;  /* Has the maximum number of elements in the stack */
    sint32_t StackTop;      /* Has the index of the top element in the stack */
}Stack_t;

/* Section : Functions Declaration */

 /**
 * @brief Creates a new stack with the specified maximum size.
 *
 * This function dynamically allocates memory for a new stack object with the given maximum size,
 * initializes its attributes, and returns a pointer to the newly created stack.
 * It also updates the status of the operation in ret_status.
 *
 * @param maxSize Maximum number of elements that the created stack can hold.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the stack creation.
 *
 * @return Stack_t* Returns a pointer to the newly created stack on success.
 *                  Returns NULL if the stack creation fails or if ret_status is a NULL pointer.
 */
Stack_t* CreateStack (uint32_t maxSize, StackStatus_t *ret_status);

 /**
 * @brief Destroys the provided stack object and releases its memory.
 *
 * This function deallocates memory for the provided stack object and its associated array of elements,
 * effectively destroying the stack. It updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) to be destroyed.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the stack destruction.
 *
 * @return Stack_t* Returns NULL after successfully destroying the stack.
 *                  Returns the original stack_obj pointer if any NULL pointer is passed.
 */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status);

 /**
 * @brief Pushes an item onto the top of the given stack.
 *
 * This function pushes an item onto the top of the provided stack object and
 * updates the status of the operation in StackStatus.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) onto which the item will be pushed.
 * @param itemPtr Pointer to the item to be pushed onto the stack.
 *
 * @return StackStatus_t Returns a status code indicating the success or failure of the push operation:
 *         - STACK_OK if the item is successfully pushed onto the stack.
 *         - STACK_FULL if the stack is full (reached its maximum capacity), preventing stack overflow.
 *         - STACK_NULL_POINTER if either stack_obj or itemPtr is a NULL pointer.
 *         - STACK_NOK if any other failure occurs during the push operation.
 */
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr);

 /**
 * @brief Pops the top element from the given stack.
 *
 * This function removes and retrieves the top element from the provided stack object and
 * updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) from which the top element will be popped.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the pop operation.
 *
 * @return void* Returns a pointer to the popped element from the stack.
 *               If the stack is empty or if any NULL pointer is passed, it returns NULL.
 */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status);

 /**
 * @brief Retrieves the top element of the given stack.
 *
 * This function retrieves the top element (most recently added) from the provided stack object and
 * returns a pointer to that element. It also updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) from which the top element will be retrieved.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the operation.
 *
 * @return void* Returns a pointer to the top element of the stack.
 *               If the stack is empty or if any NULL pointer is passed, it returns NULL.
 */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status);

 /**
 * @brief Checks the count of elements in the given stack and updates the count in stack_count.
 *
 * This function determines the count of elements present in the provided stack and
 * updates the count in the memory location pointed by stack_count parameter.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) whose count needs to be checked.
 * @param stack_count Pointer to a uint32_t variable where the count of elements will be stored.
 *
 * @return StackStatus_t Enum status indicating the success or failure of the stack count operation:
 *         - STACK_OK if the operation is successful and the count is retrieved.
 *         - STACK_EMPTY if the provided stack is empty (contains no elements), and the count is set to 0.
 *         - STACK_NULL_POINTER if either stack_obj or stack_count is a NULL pointer.
 */
StackStatus_t StackCount (Stack_t* stack_obj, uint32_t *stack_count);

#endif // STACK_ARRAY_DS_H