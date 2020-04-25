//Documentation to EVOLVE 1.0
/*
Humans are complex organisms who didn't just pop out of nothing. We are the result of billion years of painstaking evolution.
Here we take a sentence as an analogy to the complex organism we are going to mutate and evolve. Each character inside the sente-
nce is a gene. When a randomly generated character matches to that character position in the sentence, we assume that it is like a 
gene that has enables its survival. We know that a gene that has helped in an organim's survival won't be replaced unless a special
case occurs. So the characters that get matched are retained and the rest of the characters are randomized until we get the complete
sentence. So in a nutshell, We create a complex sentence from complete randomness when there is something to guide you just like 
survival for living organisms. You will understand the rest on running the cpp program

Step 1 : g++ evolution.cpp
Step 2 : .\a
*/
#include<iostream>
#include<cstring>
#include<ctime>
#include<random>
using namespace std;
/////////////////////////////Function to generate random characters as shown in set
char randomisechar(){
	char mutation_array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', ',', '.', '\'', '?'};
	int rnum;
	rnum = rand()%31;
	return mutation_array[rnum];
} 

int main(){
////////////////////////////Generating random numbers from time
	time_t t;
	srand((unsigned)time(&t));
	char word[1000]; 				
	char evolving_word[1000];
	int matched_array_flag[1000];
	char saved_evolving_word[1000];
	int score=0;
	int max_score=-1;
	int flag=0;
	int mutation=0;
	int one_cycle_iteration=0;
	int ten_iteration=0;
	int flag_not_matched = 0;

	int choice;
	cout << "\nEnter the word : ";
	cin.getline(word, 1000);
	//Inputing the word
	

	cout << "\nPrinting the mutations...";
	int wordlength = strlen(word);
	
	
	for(int m=0;m<wordlength;m++){
		saved_evolving_word[m] = '?';
		evolving_word[m]='!';
		matched_array_flag[m] = 0;
	}

	

		while(mutation<=10000000){
			if(mutation%10==0){
				flag_not_matched = 0;
				for(int l=0;l<wordlength;l++){
					if(saved_evolving_word[l]!=word[l]){
						flag_not_matched = 1;
				}
				else{
					matched_array_flag[l] = 1;
				}
			}

			cout << "\n";
			cout << "-------------->";
			for(int k=0;k<wordlength;k++)
				cout << saved_evolving_word[k];
			cout << "\n";	
		}
		if(flag_not_matched==1){
			for(int i=0;i<wordlength;i++){
				if(matched_array_flag[i]==0){
					evolving_word[i]=randomisechar();
				}
				else{
					evolving_word[i]=saved_evolving_word[i];
				}
				if(evolving_word[i]==word[i])
					score++;
			}
			if(score>max_score){
				max_score=score;
				for(int j=0;j<wordlength;j++)
					saved_evolving_word[j]=evolving_word[j];
			}
			mutation++;

			cout << "\n";
			for(int k=0;k<wordlength;k++)
				cout << evolving_word[k];
			cout << "\n";	

			score=0;
		}
		else{
			cout << "\n" << "Word evolved in " << mutation << " mutations.";
			break;
		}
			
	}
		for(int k=0;k<wordlength;k++)
			cout << saved_evolving_word[k];	

	return 0;
}
