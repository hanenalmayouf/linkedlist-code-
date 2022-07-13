#include <iostream>
#include<cmath>
#define SIZE 100
using namespace std;
struct node {
int info;
node *next;
};
class Stack{
	private :
		node* top;
		public :
			Stack(){
				top=NULL;
			}
			bool isEmpty()
			{
				if (top ==NULL)
				return true ;
				else 
				return false;
			}
			void push (int x ){
				node *p=new node ;
				p->info=x;
				p->next=top;
				top=p;
			}
			void travers(){
				if (isEmpty())
					cout <<"Stack is Empty";
				else 
				for (node*p=top;p;p=p->next)
					cout <<p->info;
			}
			int peek(){
				if (isEmpty()){
					cout<<"Stack is Empty";
					return NULL;
			}
			else return top->info;
			}
			
	 		int pop(){
			node *q;
    		if(top==NULL){
        	cout<<"Stack is Empty";
      	  return NULL;
    	}
   		 else{
        q=top;
        top = top->next;
        return q->info;
        delete q;
	  }
}
		double result(char Symbol, double Oprand1, double Oprand2){
    switch(Symbol){
        case '+' : return(Oprand1+Oprand2);
        case '-' : return(Oprand1-Oprand2);
        case '*' : return(Oprand1*Oprand2);
        case '/' : return(Oprand1/Oprand2);
        case '%' : return((int)Oprand1%(int)Oprand2);
        case '^' : return(pow(Oprand1,Oprand2));
    }
}
		double evalPostfix(char expr[]){
    int c, position;
    double opnd1,opnd2,value;
    for(position=0;(c = expr[position]) != '\0'; position++){
        if(isdigit( c ))
            push((double)(c- '0'));
        else{
                opnd1=pop();
                opnd2=pop();
                value=result(c,opnd2,opnd1);
                push(value);
            }
        }
        return pop();
}
};
int main(int argc, char** argv) {
	Stack h;
  int info, num;
 char postfix[SIZE];
  int loop=1;
  while(loop) {
  	cout <<"\n oprition on Stack by linked list \n";
    cout<<" 1-insret\n 2-travers \n 3-Delete\n 4-value in top of stack \n 5- Postfix Evaluation\n";
    cout<<" 6- exit \n";
    cout<<"\n  Enter Your Choice: ";
    cin>>num;
    switch(num) {
      case 1:
        cout<<"\n value you wanna inserted : \n";
        cin>>info;
       h.push(info);
        break;
        case 2:
        cout<<"\n values :\n";
        h.travers();
        break;
      case 3:
        cout<<"\n  deleted value: ";
      h.pop();
        break;
      case 4:
      	cout<<"\n Value in top is :"<<h.peek();
      	break;
      	case 5:
      	cout << "Enter Postfix expression:" << endl;
    	cin >> postfix;
    	cout << "The Postfix expression is: " << postfix <<endl;
    	cout << "Evaluating a postfix expression= " << h.evalPostfix(postfix)<<endl;
      	case 6:
        loop=0;
        break;
        default: cout<<"your choice not exist .. please try again.\n";
        break;
    } 
}
}
