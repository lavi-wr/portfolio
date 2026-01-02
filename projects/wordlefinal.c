#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxque 300
#define maxlen 256
#define quetoask 5

int load_questions_from_file(const char *filename, char questions[maxque][maxlen])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s.\n", filename);
        return 0;
    }

    int i = 0;
    while (fgets(questions[i], maxlen, file) && i < maxque)
    {
        // Remove the newline character from the question
        questions[i][strcspn(questions[i], "\n")] = '\0';
        i++;
    }

    fclose(file);
    return i;
}

int load_answers_from_file(const char *filename, char answers[maxque][maxlen])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s.\n", filename);
        return 0;
    }

    int i = 0;
    while (fgets(answers[i], maxlen, file) && i < maxque)
    {
        // Remove the newline character from the answer
        answers[i][strcspn(answers[i], "\n")] = '\0';
        i++;
    }

    fclose(file);
    return i;
}

void display_question(char question[], char correct_answer[])
{
    printf("\nQuestion: %s\n", question);

    printf("Answer: ");
    int length = strlen(correct_answer);
    for (int i = 0; i < length; i++)
    {
        printf("-");
    }
    printf("\n");
}

void get_user_answer(char user_answer[])
{
    printf("Please enter your answer: ");
    fgets(user_answer, maxlen, stdin);

    user_answer[strcspn(user_answer, "\n")] = '\0';
}

int check_answer(char user_answer[], char correct_answer[])
{

    if (strcmp(user_answer, correct_answer) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void select_random_questions(int selected_indices[], int total_questions)
{
    srand(time(NULL));

    for (int i = 0; i < quetoask; i++)
    {
        int random_index;
        int unique;
        do
        {
            random_index = rand() % total_questions;
            unique = 1;
            for (int j = 0; j < i; j++)
            {
                if (selected_indices[j] == random_index)
                {
                    unique = 0;
                    break;
                }
            }
        } while (unique == 0);
        selected_indices[i] = random_index;
    }
}

int main()
{
    printf("  888                888888                888       888888       888888888       8888888888       888             8888888888888\n");
    printf("   888              888  888              888      888    888     888     888     888      888     888             888          \n");
    printf("    888            888    888            888     888        888   888      888    888       888    888             888          \n");
    printf("     888          888      888          888      888        888   888     888     888        888   888             888          \n");
    printf("      888        888        888        888       888        888   888888888       888        888   888             888888888    \n");
    printf("       888      888          888      888        888        888   888    888      888        888   888             888          \n");
    printf("        888    888            888    888         888        888   888     888     888       888    888             888          \n");
    printf("         888  888              888  888            888    888     888      888    888      888     888             888          \n");
    printf("          888888                888888               888888       888       888   8888888888       8888888888888   8888888888888\n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("       8888888888              8888           888888       888888   8888888888888                                               \n");
    printf("     888                      888888          888 888     888 888   888                                                         \n");
    printf("    888                      888  888         888  888   888  888   888                                                         \n");
    printf("   888                      888    888        888   8888888   888   888                                                         \n");
    printf("   888      88888888       888888888888       888             888   888888888                                                   \n");
    printf("   888      888  888      888        888      888             888   888                                                         \n");
    printf("    888          888     888          888     888             888   888                                                         \n");
    printf("     888         888    888            888    888             888   888                                                         \n");
    printf("       88888888888     888              888   888             888   8888888888888                                               \n");
    printf("      \n");
    printf("      \n");
    printf("      \n");
    printf("      \n");
    printf("      \n");
    printf("      \n");
    char name[50];

    printf("register your name: ");
    scanf("%s", name);
    getchar();
    printf("\n--------------------- Welcome %s! -----------------------\n", name);
    printf("\nLet the world know that %s is smarter than an eighth grade student.\n", name);
    printf("\nBefore starting the game, let's go over the rules:\n");
    printf("                                                     \n");
    printf("                                                     \n");
    printf(" 1. The game will show you questions on your screen. \n");
    printf("                                                     \n");
    printf(" 2. There will be number of dashes equal to number of characters in the answer as a hint .\n");
    printf("                                                     \n");
    printf(" 3. Please use small letters for every character of every word . \n ");
    printf("                                                     \n");
    printf("                                                     \n");
    printf("                                                                                                                        \n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("     * * * *     * * * *               *              * * * * *   * * * * * *                            \n");
    printf("     *      *    *      *             * *            *            *                                                     \n");
    printf("     *       *   *       *           *   *          *             *                                                      \n");
    printf("     *      *    *      *           *     *        *              *                                                       \n");
    printf("     * * * *     * * * *           * * * * *       *              * * * *                                                                \n");
    printf("     *      *    *      *         *         *      *              *                                                        \n");
    printf("     *       *   *       *       *           *      *             *                                                       \n");
    printf("     *      *    *        *     *             *      *            *                                                        \n");
    printf("     * * * *     *         *   *               *      * * * * *   * * * * * *                                                                     \n");

    printf("                                                                                                                                                                                                            \n");
    printf("                                                                                                                                                                                                            \n");
    printf("                                                                                                                                                                                                            \n");
    printf(" *       *      * * * *      *         *   * * * *         * * * *     * * * * * *   *             * * * * * *                                                                                                                                          \n");
    printf("  *     *      *       *     *         *   *      *       *            *             *             *                                                                                                                  \n");
    printf("   *   *      *         *    *         *   *       *     *             *             *             *                                                                                                                  \n");
    printf("    * *      *           *   *         *   *      *       *            *             *             *                                                                                                                  \n");
    printf("     *       *           *   *         *   * * * *         * * * *     * * * *       *             * * * *                                                                                                                            \n");
    printf("     *       *           *   *         *   *      *               *    *             *             *                                                                                                                 \n");
    printf("     *        *         *    *         *   *       *               *   *             *             *                                                                                                                 \n");
    printf("     *         *       *      *       *    *        *             *    *             *             *                                                                                                                 \n");
    printf("     *          * * * *        * * * *     *         *     * * * *     * * * * * *   * * * * * *   *                                                                                                                                          \n");
    printf("                                                                                                                                \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("       8888888888              8888           888888       888888   8888888888888                                               \n");
    printf("     888                      888888          888 888     888 888   888                                                         \n");
    printf("    888                      888  888         888  888   888  888   888                                                         \n");
    printf("   888                      888    888        888   8888888   888   888                                                         \n");
    printf("   888      88888888       888888888888       888             888   888888888                                                   \n");
    printf("   888      888  888      888        888      888             888   888                                                         \n");
    printf("    888          888     888          888     888             888   888                                                         \n");
    printf("     888         888    888            888    888             888   888                                                         \n");
    printf("       88888888888     888              888   888             888   8888888888888                                               \n");
    printf("                                                     \n");
    printf("                                                     \n");
    printf("                                                     \n");
    printf("         * * * *     * * * * * * *             *          * * * *      * * * * * * *                      \n");
    printf("        *                  *                  * *         *      *           *                            \n");
    printf("       *                   *                 *   *        *       *          *                            \n");
    printf("        *                  *                *     *       *      *           *                            \n");
    printf("         * * * *           *               * * * * *      * * * *            *                            \n");
    printf("                *          *              *         *     *      *           *                            \n");
    printf("                 *         *             *           *    *       *          *                            \n");
    printf("                *          *            *             *   *        *         *                            \n");
    printf("         * * * *           *           *               *  *         *        *                                \n");

    char questions[maxque][maxlen];
    char answers[maxque][maxlen];
    char user_answer[maxlen];
    int total_questions, score = 0;

    total_questions = load_questions_from_file("question.txt", questions);
    if (total_questions == 0)
    {
        return 1;
    }

    int total_answers = load_answers_from_file("result.txt", answers);
    if (total_answers == 0 || total_answers != total_questions)
    {
        printf("Error: Number of answers does not match number of questions.\n");
        return 1;
    }

    int index[quetoask];

    select_random_questions(index, total_questions);

    for (int i = 0; i < quetoask; i++)
    {
        int quesindex = index[i];
        display_question(questions[quesindex], answers[quesindex]);
        get_user_answer(user_answer);
        int result = check_answer(user_answer, answers[quesindex]);
        if (result == 1)
        {
            score++;
        }
    }

    printf("\nYour total score is: %d out of %d\n", score, quetoask);
    if (score == quetoask)
        printf("congrats %s !! you are smater than a eighth grade student");
    else
        printf(" sorry !! ask for refund from your school\n\n");

    printf("\nCorrect answers:\n");
    for (int i = 0; i < quetoask; i++)
    {
        int quesindex = index[i];
        printf("Question: %s\n", questions[quesindex]);
        printf("Correct answer: %s\n\n", answers[quesindex]);
    }

    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("                                                                                                                                \n");
    printf("       8888888888              8888           888888       888888   8888888888888                                               \n");
    printf("     888                      888888          888 888     888 888   888                                                         \n");
    printf("    888                      888  888         888  888   888  888   888                                                         \n");
    printf("   888                      888    888        888   8888888   888   888                                                         \n");
    printf("   888      88888888       888888888888       888             888   888888888                                                   \n");
    printf("   888      888  888      888        888      888             888   888                                                         \n");
    printf("    888          888     888          888     888             888   888                                                         \n");
    printf("     888         888    888            888    888             888   888                                                         \n");
    printf("       88888888888     888              888   888             888   8888888888888                                               \n");
    printf("                                                     \n");
    printf("                                                     \n");
    printf("                                                     \n");
    printf("    & & & & & &   &         &   & & & & &                                                             \n");
    printf("    &             & &       &   &        &                                                           \n");
    printf("    &             &  &      &   &         &                                                          \n");
    printf("    &             &   &     &   &          &                                                         \n");
    printf("    & & & & &     &    &    &   &          &                                                         \n");
    printf("    &             &     &   &   &          &                                                          \n");
    printf("    &             &      &  &   &         &                                                           \n");
    printf("    &             &       & &   &        &                                                            \n");
    printf("    & & & & & &   &         &   & & & & &                                                            \n");

    return 0;
}