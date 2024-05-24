#include <stdio.h>
#include <stdlib.h>

void castVote(char candidates[5][14],int* votes){
	int choice = 0;
	printf("\n1. Jhon Doe\n2. Ima Knight\n3. Hillary Clark\n4. William Smith\n5. None of These\n");
	printf("Please enter your choice (1-5): ");
	scanf("%d",&choice);

	votes[choice-1]+=1;
	printf("Thanks for vote!\n\n");
}

void votesCount(int* votes){
	printf("###### Voting Statistics ######\n");
	printf("Jhon Doe-%d\n",votes[0]);
	printf("Ima Knight-%d\n",votes[1]);
	printf("Hillary Clark-%d\n",votes[2]);
	printf("William Smith-%d\n",votes[3]);
	printf("Spoiled Votes-%d\n",votes[4]);
}
void getleadingCandidate(char names[][14],int* votes){
	int biggest = 0;
	int i,count = 0;
	for (i=1;i<5;i++){
		if (votes[i]>votes[biggest]){
			biggest = i;
		}
	}
	for(i=0;i<5;i++){
		if (votes[i]==votes[biggest]){
			count++;
		}
	}
	if(count==1){
		printf("[%s]\n",names[biggest]);	
	}
	else{
		printf("No winner\n");
	}


}
int main()
{
//array
char candidates[5][14] = {"Jhon Doe", "Ima Knight", "Hillary Clark", "William Smith", "None of These"};
int votes[5] = {0,0,0,0,0};

int choice = 0;
while (choice != 4){
	printf("###### Welcome to Election/Voting 2021 ######");
	printf("\n\n1. Cast the Vote\n2. Find Vote Count\n3. Find leading Candidate\n4. Exit\n\n");
	printf("Please enter your choice (1-4): ");
	scanf("%d",&choice);
	
	if (choice==1){
		castVote(candidates,votes);
	}
	else if (choice==2){
		votesCount(votes);
	}
	else if (choice==3){
		getleadingCandidate(candidates,votes);
	}
}
return 0;
}
