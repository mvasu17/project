#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a quiz question
struct Question {
    char question[256];
    char options[4][100];
    char correct_answer;
};

// Function to display a single question and get the answer
int ask_question(struct Question q) {
    int answer;
    printf("\n%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
    printf("Enter your choice (1-4): ");
    scanf("%d", &answer);
    if (answer == (q.correct_answer - 'A' + 1)) {
        return 1; // Correct answer
    }
    return 0; // Incorrect answer
}

int main() {
    int score = 0;
    struct Question questions[] = {
        {"What is the capital of France?",
         {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"},
         'C'},

        {"Which language is known as the 'Mother of all languages'?",
         {"A. C", "B. Python", "C. Java", "D. Assembly"},
         'A'},

        {"What is the largest planet in our solar system?",
         {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
         'C'},

        {"Who developed the theory of relativity?",
         {"A. Isaac Newton", "B. Nikola Tesla", "C. Albert Einstein", "D. Galileo"},
         'C'},

        {"What is the chemical symbol for water?",
         {"A. CO2", "B. H2O", "C. O2", "D. H2SO4"},
         'B'}
    };

    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Greet the user
    printf("Welcome to the Online Quiz System!\n");
    printf("Answer the following questions:\n");

    // Loop through each question and ask
    for (int i = 0; i < num_questions; i++) {
        if (ask_question(questions[i])) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was %c\n", questions[i].correct_answer);
        }
    }

    // Display the final score
    printf("\nYour final score is: %d/%d\n", score, num_questions);
    printf("Thanks for playing!\n");

    return 0;
}
