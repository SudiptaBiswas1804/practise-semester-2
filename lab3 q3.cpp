#include <iostream>
#include <string.h>
using namespace std;

//structure of the node
class issue{
public:
char name[30];
int phone;
char des[30];
issue *next;
issue(){
next=NULL;
}
};

//Structure of the string push and pop function
class strpal{
public:
char nm[30];
void push(char a){
nm[top]=a;
top++;
}
void pop(){
top--;
}
};

//Class for customer service
class customerservice{
private:
issue *head;
issue *tail;
public:
customerservice(){
head=NULL;
tail=NULL;
}
int chkpalindrome( char name[30]);
void addissue( char name[30]; int phone; char des[30]);
void displayissue();
};

//checking palindrome
int customerservice::chkpalindrome(char name[30]){
top=-1;
front=0;
char b;
for(int i=0; name[i]!='\0'; i++){          //for adding the elements
b=char name[30];
stack.push(b);
}
for (int i=0; i<(signed)(strlen(name)/2); i++){      //for checking the palindromes
if (stack.nm[top]==stack.nm[front]){
stack.pop();
front++;
}
else {
retutn 0;
}
}
int x=front;
front=0;
top=-1;
if((signed)(strlen(name)/2)==x){
return 1;
}
return -1;
}

