#include<iostream>
#include<string>
#include <bits/stdc++.h> 
#include<stdio.h>
#include<conio.h>
using namespace std;
struct test{
    int qno;
    string ques;
    string ans;
    test *next;
};

class subject{
    string sid;
    string sname;
    test *head;

    public:
    subject(string s, string id){
        sid = id;
        sname = s;
        head = NULL;
        cout<<"Subject: "<<s<<endl<<"Subject code: "<<id<<endl;
    }
 
    void Driver(){
        int c;
        cout<<"1. View Notes"<<endl
            <<"2. Add Notes"<<endl
            <<"3. Take Test"<<endl
            <<"4. Brain Teaser"<<endl
            <<"0. Logout"<<endl;
            cin>>c;
        while(c!=0){
            switch(c){
                case 1: viewNotes(head);
                        break;
                case 2: head = addNotes(head);
                        break;
                case 3: takeTest(head);
                        break;
                case 4: brainTeaser();
                        break;
                default: cout<<"ERROR: Invalid Input"<<endl;
            }
            cout<<"1. View Notes"<<endl
                <<"2. Add Notes"<<endl
                <<"3. Take Test"<<endl
                <<"4. Brain Teaser"<<endl
                <<"0. Logout"<<endl;
                
            cin>>c;
        }
        
    }

    void print(test *p){
        cout<<"Question:"<<p->qno<<" "<<p->ques<<endl
            <<"Answer: "<<p->ans<<endl;
    }

    test* input(test *p){                                                                   //INPUT
        cout<<"Enter Question: "<<endl;
        cin.get();
        getline(cin,p->ques);
        //p->ques="QuestionSample";
        //cout<<1;
        cout<<"Enter Answer: "<<endl;
        //cin.get();
        getline(cin,p->ans);
        //p->ans="AnswerSample";
        p->next=NULL;
        return p;
    }
 
    void viewNotes(test *p){
        if(p==NULL){
            cout<<"The question paper has not been set"<<endl;
            return;
        }
        else{
            while(p){
                print(p);
                p=p->next;
            }
        }
    }

    test* addNotes(test *t){
        //int choice;
      /*  cout<<"1. Add a question"<<endl
            <<"2. Edit a Question"<<endl;
        cin>>choice;*/
            test *h = t;
            test *p = new test;
            if(t==NULL){
                
                p = new test;
                p->qno = 1;
                p = input(p);
                h=p;
               
            }
            else{
                while(t->next){
                t = t->next;
                }
                t->next=p;
                p->qno = t->qno +1;
                p = input(p);
            }
            
            cout<<"Question Added Successfully"<<endl;
            return h;
        
    }

    void takeTest(test *t){
        int maxMarks = 0;
        if(t==NULL){
            cout<<"Test Unavailable"<<endl;
            return;
        }
        int points = 0;
        while(t){
           
            int choice;
            cout<<t->ques<<endl;
            cout<<"1. Give your answer"<<endl
                <<"2. Show hints"<<endl;
            cin>>choice;
            if(choice == 1){
                cout<<"Enter the answer: "<<endl;
                string ans;
                cin.get();
                getline(cin,ans);                                                         //INPUT
                //ans = "AnswerSample";
                if(ans.compare(t->ans)==0){
                    cout<<"Correct Answer"<<endl;
                    points+=4;
                }
                else{
                    cout<<"Wrong Answer"<<endl;
                    points-=1;
                }
                t = t->next;
            }
            else if(choice==2){
                points+=play(t);
                t=t->next;
                

            }
            else{
                cout<<"Wrong Choice"<<endl;
            }
            maxMarks++;
            //cout<<++maxMarks;
        
        }
        cout<<"You have scored"<<points<<"/"<<maxMarks*4<<endl;
    }

    int play(test *t){
        int points = 1;
        string word = t->ans;
        //cout<<word<<endl;
        string qn;
        int n = word.length();
        for(int i=0;i<n;i++){
            qn.push_back('_');
        }
        
        for(int i=0;i<n;i++){
            cout<<qn[i]<<" ";
        }
        cout<<endl;
        int count = 0;
        while(qn!=word){
            int choice;
            cout<<"Enter 1 to guess the answer or 2 to unlock a character";
            cin>>choice;
            if(choice==1){
                cout<<"Your answer: "<<endl;
                string ans;
                cin.get();
                getline(cin,ans);                                                             //INPUT
                //ans = "AnswerSample";
                if(ans.compare(word)==0){
                    cout<<"Correct Answer"<<endl;
                    points = 2 ;
                    break;
                }
                else{
                    cout<<"Wrong Answer"<<endl;
                    points = -1;
                    break;
                }
            }
            else if(choice==2){
                cout<<"Enter the character: "<<endl;
                char c ;
                cin>>c;
                string ch(1,c);
                int check=0;
                for(int i=0;i<word.length();i++){
                       if(c==word[i]){
                           
                           qn.replace(i,1,ch);
                           check=1;
                           count++;
                       }
                }
                if(check==1){
                    for(int i=0;i<n;i++){
                        cout<<qn[i]<<" ";
                    }
                    cout<<endl;
                }
                else{
                    cout<<"Character not found"<<endl;
                    count++;
                }
                if(count>n+3){
                    cout<<"Sorry, you have used up all hints. The courrect answer is: "<<t->ans<<endl;
                    points = -2;
                    break;
                }
                
            }
            else{
                cout<<"Wrong Choice";
            }
        }

        return points;
        
    }

    void brainTeaser(){
        
        stack <int> s;
        s.push(23);
        s.push(78);
        s.push(2);
        s.push(10); 
        s.push(9);
        s.push(1);

        cout << "------------------------------------------------------------------------------------------------" << endl ;
        cout << "| --------------------------------------------------------------------------------------------  |" << endl ;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;    
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                       BRAIN TEASER                                        " << "| |" << endl;
        cout << "| |" <<"                                 Here you go with the game                                 " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                 Rules are pretty simple                                   " << "| |" << endl;
        cout << "| |" <<"                1. You'll be given 6 numbers that you have to memorize.                    " << "| |" << endl;
        cout << "| |" <<"                2. The numbers will be shown to you for only 6 seconds                     " << "| |" << endl;
        cout << "| |" <<"                3. You will be asked to tell the numbers in the reverse order.             " << "| |" << endl;
        cout << "| |" <<"                4. Only two chances will be given to you.                                  " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| |" <<"                                                                                           " << "| |" << endl;
        cout << "| --------------------------------------------------------------------------------------------  |" << endl ;
        cout << "------------------------------------------------------------------------------------------------" << endl ;
        
        char ans;
        cout << "So shall we start?(y/n)";
        cin >> ans;
        if(ans == 'n'){
            cout<<"Let's get back to study!";
            return;
        }
        cout << flush; //flush forces the printing to the screen before it clears
        system ("cls");
        cout << "------------------------------------------------------------------------------------------------" << endl ;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;    
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                 23          78           2       10        9              1             " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "|" <<"                                                                                         " << "|" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl ;
        getch();
        cout << flush; //flush forces the printing to the screen before it clears
        system ("cls");
        
        int k;
        cout << "Here you go!" << endl;
        cin >> k;
        if(s.top() != k) 
        {
            cout << "Lost one life" << endl;
            return;
            
        }
        else s.pop();
        cin >> k;
        if(s.top() != k) 
        {
            cout << "You lost" << endl;
            return;
            
            
        }
        else s.pop();
        cin >> k;
        if(s.top() != k) 
        {
            cout << "You lost" << endl;
            return;
                
            
        }
        else s.pop();
        cin >> k;
        if(s.top() != k) 
        {
            cout << "You lost" << endl;
            return;
                
            
        }
        else s.pop();
        cin >> k;
        if(s.top() != k) 
        {
            cout << "Lost one life" << endl;
            return;
                
            
        }
        else s.pop();

        cout << "You Won!!!";
    } 

};

int main(){
    string subName,subId;
    cout<<"Enter Subject: ";
    getline(cin,subName);
    cout<<"Enter Subject Code";
    getline(cin,subId);
    subject S(subName, subId);
    S.Driver();
    return 0;
}
