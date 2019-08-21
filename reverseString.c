/*
Programmer: Joshua Doucet
Date: 4-20-2019
Description: Reversing the text in a string. 
   The program prompts a user for a string input followed by a new line character.
   The program then inputs each character into a stack and outputs the user input in reverse
   by poppoing all of the characters in the stack.

*/

#include <stdio.h>

//A node which char data used in 
typedef struct charNode {
   char data;
   struct charNode *nextPtr;
} CharNode;
typedef CharNode* CharNodePtr;

//pop stack implementation for stacks with nodes that have char data, returns data
char pop(CharNodePtr *stackPtr);

//push data to stacks that contain nodes with char data, returns 1 for success, and 0 for failure
_Bool push(CharNodePtr *stackPtr, char data);

//Prompts a user for a line of text followed by an endline character.
//the user input text is then reversed and printed to the application console.
//The revesal is done by pushing and popping characters from a stack.
void reverseInput();

int main(void) {
   //Output title and instructions to user
   puts("Reversing Strings\n----------------------");
   printf_s("Enter some text to get it reversed.\n");

   //Var to store user choice to continue
   char again = 'Y';
   //Reverse strings until Y or y is entered when prompted to continue
   while (again == 'y' || again == 'Y') {
      reverseInput();
      printf_s("\n\nContinue? (Y/N)\n? ");
      scanf_s(" %c", &again);
      while (getchar() != '\n'); //clear stream
   }

   return 0;
}

_Bool push(CharNodePtr *stackPtr, char data) {
   //Create new node
   CharNodePtr newNodePtr = malloc(sizeof(CharNode));
   if (newNodePtr != NULL) {
      //If successful assign data to new node
      newNodePtr->data = data;
      //link new node to the stack
      newNodePtr->nextPtr = *stackPtr;
      //point the top of the stack to the new node
      *stackPtr = newNodePtr;
      return 1; //push successful
   }
   else
      return 0; //push failed
}

char pop(CharNodePtr *stackPtr) {
   //copy data from top node
   char data = (*stackPtr)->data;
   //create a temp node and set it equal to the stack top
   CharNodePtr temp = *stackPtr;
   //unlink the top node from the stack
   *stackPtr = (*stackPtr)->nextPtr;
   //delete temp node
   free(temp);
   return data;
}

void reverseInput() {
   //A stack is used to reverse the user input strings
   CharNodePtr stackPtr = NULL;

   printf_s("\nText to be reversed\n? ");
   //Push each user input character to stack until new line is entered.
   char c;
   while ((c = getchar()) != '\n') {
      push(&stackPtr, c);
   }

   //Pop each character from the stack, and print user input in reverse to application window
   while (stackPtr != NULL) {
      printf_s("%c", pop(&stackPtr));
   }
}

/*
Copyright [2019] [Joshua Doucet]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/