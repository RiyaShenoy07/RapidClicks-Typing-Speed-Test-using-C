#include <stdio.h>
#include <string.h>
#include <time.h>

// initialization

int main (){
    char sample[] = "Hello I am human and i am the most intelligent living being on earth. i can even control things on earth and have potential to create the universe";
    char input[500];
    int correctChars = 0;
    clock_t start, end;
    double time_taken, wpm, accuracy;

 printf("Typing Speed Test\n");
 printf("Type the following sentence:\n\n%s\n\n", sample);
 printf("Press Enter when you finish.\n");

 // start time

 start = clock();
 fgets(input, sizeof(input), stdin);
 end = clock();

// remove new line from input
input[strcspn(input, "\n")] = 0;

//time calculation
time_taken = ((double)(end - start))/CLOCKS_PER_SEC; //Seconds

// count correct charaters
for(int i=0; strlen(sample) && i<strlen(input); i++){
    if(sample[i] == input[i]){
        correctChars++;
    }
}
// words per minute (approx 5 chars = 1 word)
    wpm = ((double)strlen(input) / 5) / (time_taken / 60);

    // accuracy
    accuracy = ((double)correctChars / strlen(sample)) * 100;

    printf("\n--- Results ---\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f WPM\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}

