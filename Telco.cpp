<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> time_call_from;
unordered_map<string, int> number_call_from;
int number_of_call = 0;
int check_phone_number_is = 1;

void check_phone_number(string phone){
    if (phone.length()!=10){
        check_phone_number_is = 0;
        return;
    }
    for (int i=0; i<10; i++ ){
        if(phone[i]>'9' && phone[i]<'0'){
            check_phone_number_is = 0;
        }
    }
    return;
}

int time_call(string from_time, string to_time){
    int h = 10*(to_time[0] - from_time[0]) + (to_time[1]-from_time[1]);
    int m = 10*(to_time[3] - from_time[3]) + (to_time[4]-from_time[4]);
    int s = 10*(to_time[6] - from_time[6]) + (to_time[7]-from_time[7]);

    return 3600*h + 60*m +s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1){
        string s;
        cin >> s;
        if(s=="#"){
            break;
        }

        string phone1, phone2, date, from_time, to_time;

        cin >> phone1 >> phone2 >> date >> from_time >> to_time;

        number_of_call++;

        if(check_phone_number_is==1){
            check_phone_number(phone1);
            check_phone_number(phone2);
        }

        if(number_call_from.find(phone1)==number_call_from.end())
        {
            number_call_from[phone1]=1;
        }
        else
        {
            number_call_from[phone1]++;
        }

        if(time_call_from.find(phone1)==time_call_from.end()){
            time_call_from[phone1]=time_call(from_time, to_time);
        }
        else{
            time_call_from[phone1]+=time_call(from_time, to_time);
        }
    }

    while(1){
        string s;
        cin >> s;
        if(s=="#"){
            break;
        }

        if(s=="?check_phone_number"){
            cout<<check_phone_number_is<<"\n";
        }

        if(s=="?number_total_calls"){
            cout<<number_of_call<<"\n";
        }

        if(s=="?number_calls_from"){
            string phone;
            cin >> phone;
            cout<<number_call_from[phone]<<"\n";
        }

        if(s=="?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout<<time_call_from[phone]<<"\n";
        }
    }
    return 1;
=======
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> time_call_from;
unordered_map<string, int> number_call_from;
int number_of_call = 0;
int check_phone_number_is = 1;

void check_phone_number(string phone){
    if (phone.length()!=10){
        check_phone_number_is = 0;
        return;
    }
    for (int i=0; i<10; i++ ){
        if(phone[i]>'9' && phone[i]<'0'){
            check_phone_number_is = 0;
        }
    }
    return;
}

int time_call(string from_time, string to_time){
    int h = 10*(to_time[0] - from_time[0]) + (to_time[1]-from_time[1]);
    int m = 10*(to_time[3] - from_time[3]) + (to_time[4]-from_time[4]);
    int s = 10*(to_time[6] - from_time[6]) + (to_time[7]-from_time[7]);

    return 3600*h + 60*m +s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1){
        string s;
        cin >> s;
        if(s=="#"){
            break;
        }

        string phone1, phone2, date, from_time, to_time;

        cin >> phone1 >> phone2 >> date >> from_time >> to_time;

        number_of_call++;

        if(check_phone_number_is==1){
            check_phone_number(phone1);
            check_phone_number(phone2);
        }

        if(number_call_from.find(phone1)==number_call_from.end())
        {
            number_call_from[phone1]=1;
        }
        else
        {
            number_call_from[phone1]++;
        }

        if(time_call_from.find(phone1)==time_call_from.end()){
            time_call_from[phone1]=time_call(from_time, to_time);
        }
        else{
            time_call_from[phone1]+=time_call(from_time, to_time);
        }
    }

    while(1){
        string s;
        cin >> s;
        if(s=="#"){
            break;
        }

        if(s=="?check_phone_number"){
            cout<<check_phone_number_is<<"\n";
        }

        if(s=="?number_total_calls"){
            cout<<number_of_call<<"\n";
        }

        if(s=="?number_calls_from"){
            string phone;
            cin >> phone;
            cout<<number_call_from[phone]<<"\n";
        }

        if(s=="?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout<<time_call_from[phone]<<"\n";
        }
    }
    return 1;
>>>>>>> 2363758 (Initial commit)
}