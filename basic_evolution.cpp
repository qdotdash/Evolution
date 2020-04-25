#include<iostream>
#include<cstring>
#include<ctime>
#include<random>
using namespace std;

char randomisechar(){
	char mutation_array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
	int rnum;
	rnum = rand()%27;
	return mutation_array[rnum];
} 
int main(){
	time_t t;
	srand((unsigned)time(&t));
	char word[100];
	char evolving_word[100];
	int matched_array_flag[100];
	char saved_evolving_word[100];
	int score=0;
	int max_score=-1;
	int flag=0;
	int mutation=0;
	int one_cycle_iteration=0;
	cout << "Enter the word : ";
	cin >> word;
	cout << "\nPrinting the mutations...";
	int wordlength = strlen(word);
	int ten_iteration=0;
	int flag_not_matched = 0;
	
	for(int m=0;m<wordlength;m++){
		saved_evolving_word[m] = '?';
		matched_array_flag[m] = 0;
	}

	

		while(mutation<=10000000){
			if(mutation%10==0){
				flag_not_matched = 0;
				for(int l=0;l<wordlength;l++){
					if(saved_evolving_word[l]!=word[l]){
						flag_not_matched = 1;
						break;
				}
			}
		}
		if(flag_not_matched==1){
			for(int i=0;i<wordlength;i++){
				evolving_word[i]=randomisechar();
				if(evolving_word[i]==word[i])
					score++;
			}
			if(score>max_score){
				max_score=score;
				for(int j=0;j<wordlength;j++)
					saved_evolving_word[j]=evolving_word[j];
			}
			mutation++;

			/*cout << "\n";
			for(int k=0;k<wordlength;k++)
				cout << evolving_word[k];
			cout << "\n";	*/

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
