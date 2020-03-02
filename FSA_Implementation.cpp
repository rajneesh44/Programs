#include <iostream>
#include <set>
#include <stdlib.h>
#include <iterator>
#define sigma 2
#include<fstream>

using namespace std;
struct unit{
	set<int> blocks;
};
int next_state(unit tt[][sigma], int ps, int pi, int count){
	set<int>::iterator it = tt[ps][pi].blocks.begin();
	
	while(count-->0){
		it++;
	}
	return *(it);
}

bool fsa(unit tt[][sigma], int present_state, int inp_index, string inp, set<int> final_states){

	if(inp_index==-1){
		if(final_states.find(present_state)!= final_states.end()){
			cout<<"String is accepted"<<endl;
			return true;
		}
		else{
			cout<<"String is rejected"<<endl;
			return false;
		}
	}
	int next_input = inp[inp_index++] -'0';
	if(inp_index==inp.length()){
		inp_index = -1;
	}
	
	int count = tt[present_state][next_input].blocks.size();
	int i=0;
	
	while(i<count){
		int n_state = next_state(tt, present_state, next_input, i);
		cout<<"Next state for "<<next_input<<" is q"<<n_state<<endl;
		bool test = fsa(tt, n_state, inp_index, inp, final_states);
		i++;
	}
}
int main(){
	int Q = 3;   //no of states
//	int sigma = 2;    //set of input symboles or alphabet
	int q = 0;   //initial state
	int F = 1;      //final state
//	string inp = "0010001";  //input string
	string inp="101110";
	
//	ifstream file_("nfa.txt");	
//    file_ >> Q>> q>>F;
////    for(i=0; i<F; i++)  {
////        file_ >> X;
////        finalStates[X] = true;
////    }
	
	unit tt[Q][sigma];
	
//	tt[0][0].blocks.insert(0);
//	tt[0][1].blocks.insert(0);
//	tt[0][1].blocks.insert(1);
//	tt[1][0].blocks.insert(2);
//	tt[1][1].blocks.insert(2);
//	tt[2][0].blocks.insert(2);
//	tt[2][1].blocks.insert(2);

	tt[0][0].blocks.insert(1);
	tt[0][1].blocks.insert(0);
	tt[0][1].blocks.insert(1);
	tt[1][0].blocks.insert(2);
	tt[1][1].blocks.insert(0);
	tt[2][0].blocks.insert(2);
	tt[2][1].blocks.insert(2);
	
	set<int> final_states;
	final_states.insert(2);
	
	bool answ = fsa(tt, 0, 0, inp, final_states);

}
