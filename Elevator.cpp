#include <iostream>
#include <list>
using namespace std;


class Queue{

private:

struct node {
   int Floor;
   struct node *next;
};



struct node* front = NULL;
struct node* rear = NULL;



public:

void Enqueue(int d) {

    struct node* tmp=new node;

   if (rear == NULL) {

      tmp->next = NULL;
      tmp->Floor = d;
      rear=tmp;
      front = rear;
   }

   else {
      rear->next = tmp;
      tmp->Floor = d;
      tmp->next = NULL;
      rear = tmp;
   }
}


int Dequeue() {

    struct node* tmp = front;
    int data;

    if (front == NULL) {
      return 0;
     }



   else{

   data=front->Floor;

   if (tmp->next != NULL) {
      tmp=front;
      front = front->next;
      delete tmp;
   }

     else {

      tmp=front;
      front = NULL;
      rear = NULL;
       delete tmp;
    }

  }


 return data;



}



void Display() {

  struct node* temp = front;

   if (front == NULL) {
      cout<<"Queue is empty"<<endl;
      return;
   }


   while (temp != NULL) {
      cout<<temp->Floor<<"\n";
      temp = temp->next;
   }


 }


 int Size() {

  struct node* temp = front;
  int cnt=0;

   while (temp != NULL) {
      cnt++;
      temp = temp->next;
   }

   return cnt;

 }


int Delete_at(int index){

     int ar_size=Size();
     int data_arr[ar_size-1];
     int cnt=0;
     int tmp=0 ;

     if(index > Size()){
        cout<<"\n"<<"Error: out of bounds !";
        return 0;
    }

     for(int i=0;i<ar_size;i++){


         if(i == (index-1)){
             tmp = Dequeue();


         }


         else{
             data_arr[cnt]=Dequeue();
             cnt++;
         }



     }





     for(int i=0;i<ar_size-1;i++){

        // cout<<"\n array  : "<<data_arr[i];

         Enqueue(data_arr[i]);

     }



       return tmp;

 }







};



class Elevator{

private:
int lift_1;
int lift_2;
int current_l;
int position;
int Highest_Floor;
int Lowest_Floor;
Queue Q;

public:
Elevator(){
    lift_1=1;
    lift_2=1;
    current_l=1;
    Highest_Floor=15;     //default
    Lowest_Floor=1;       //default
}

void set_lift1(int floor){

if(floor==0){
 cout<<"\n"<<"Please Choose A Valid Floor Number !"<<"\n";
return;
}

lift_1=floor;

}
void set_lift2(int floor){

if(floor==0){
 cout<<"\n"<<"Please Choose A Valid Floor Number !"<<"\n";
return;
}

lift_2=floor;

}

void set_Highest_Floor(int Hfloor){

 Highest_Floor=Hfloor;

}


void set_Lowest_Floor(int Lfloor){

  if(Lfloor==0){
    cout<<"\n"<<"Please Choose A Valid Floor Number !"<<"\n";
      return;
  }
 Lowest_Floor=Lfloor;

}


void Request_Floor(int floor){

    if(floor>Highest_Floor){
        cout<<"\n"<<" Requested Floor is higher than the building highest floor !" <<"\n";
          return;
    }

     if(floor<Lowest_Floor){
        cout<<"\n"<<" Requested Floor is lower than the building lowest floor !" <<"\n";
        return;
    }


   Q.Enqueue(floor);

}

void Calculate_Steps(int cur_floor){


    int lift1_steps;
    int lift2_steps;

          if(cur_floor>lift_1){
               lift1_steps=cur_floor - lift_1;
               position = 1;
           }

           else if(cur_floor<lift_1){

               lift1_steps=lift_1 - cur_floor;
                position = -1;
           }

            if(cur_floor>lift_2){

               lift2_steps=cur_floor - lift_2;
                position = 1;
           }


            else  if(cur_floor<lift_2){

               lift2_steps=lift_2 - cur_floor;
                position = -1;
           }


           if(lift1_steps>lift2_steps){

               current_l=2;
           }

           else if(lift1_steps<lift2_steps){

               current_l=1;
           }

            else if (lift1_steps==lift2_steps){

               current_l=1;
           }


}



void  execute(){
int i;
int cur_request;

while(Q.Size()!=0){
 cur_request=Q.Dequeue();

 if(cur_request==lift_1){
    cout<<"lift 1 was in floor  "<<lift_1<<" then moved to floor  "<<cur_request<<endl;
    current_l=1;

 }


 else if(cur_request==lift_2){
        cout<<"lift 2 was in floor  "<<lift_2<<" then moved to floor  "<<cur_request<<endl;
        current_l=2;

 }

 else{

    Calculate_Steps(cur_request);
    int ar_size=Q.Size();
    int requests[ar_size]={0};
    int next_request;

    for(int j=0;Q.Size()!=0;j++){
      next_request=Q.Dequeue();


         if(current_l==1){


            if(position==1){

               if(next_request >= lift_1 && next_request <= cur_request){


                 cout<<"lift 1 was in floor  "<<lift_1<<" then moved to floor  "<<next_request<<endl;

                   lift_1=next_request;
                }

               else{
                  requests[j]=next_request;
               }
            }

           else if(position==-1){

              if(next_request <= lift_1 && next_request >= cur_request){

                    cout<<"lift 1 was in floor  "<<lift_1<<" then moved to floor  "<<next_request<<endl;

                   lift_1=next_request;
                }


              else{
                  requests[j]=next_request;
               }

           }

       }


     else if(current_l==2){


            if(position==1){

               if(next_request >= lift_2 && next_request <= cur_request){


                 cout<<"lift 2 was in floor  "<<lift_2<<" then moved to floor  "<<next_request<<endl;

                   lift_2=next_request;
                }

               else{
                  requests[j]=next_request;
               }
            }

           else if(position==-1){

              if(next_request <= lift_2 && next_request >= cur_request){

                    cout<<"lift 2 was in floor  "<<lift_2<<" then moved to floor  "<<next_request<<endl;

                   lift_2=next_request;
                }


              else{
                  requests[j]=next_request;
               }

           }

         }


       }



       if(current_l == 1){
         cout<<"lift 1 was in floor  "<<lift_1<<" then moved to floor  "<<cur_request<<endl;
         lift_1=cur_request;
       }

       else if (current_l == 2){
         cout<<"lift 2 was in floor  "<<lift_2<<" then moved to floor  "<<cur_request<<endl;
         lift_2=cur_request;
       }

       for(int j=0;j<ar_size;j++){

          if(requests[j]!=0){
            Q.Enqueue(requests[j]);
          }

       }



   }



   i++;
 }


}




};


int main() {
   Elevator q;
    q.set_lift2(4);
    q.Request_Floor(2);
    q.Request_Floor(5);
    q.Request_Floor(7);
    q.Request_Floor(1);
    q.Request_Floor(3);
    q.Request_Floor(4);

    q.execute();








  return 0;
}
