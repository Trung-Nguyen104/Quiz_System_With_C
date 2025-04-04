#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 10

typedef struct {
    char question[100];
    char options[3][50];
    char correctAnswer;
} Question;

void saveResult(const char *name, int score) {
    FILE *file = fopen("history.txt", "a");
    if (file == NULL) {
        printf("Lỗi khi lưu điểm!\n");
        return;
    }
    fprintf(file, "Người chơi: %s - Điểm: %d\n", name, score);
    fclose(file);
}

char getUserAnswer() {
    char answer;
    scanf(" %c", &answer);
    return tolower(answer);
}

void askQuestion(Question q, int *score) {
    char userAnswer;
    printf("\n%s\n", q.question);
    printf("a. %s\nb. %s\nc. %s\n", q.options[0], q.options[1], q.options[2]);
    printf("Nhập đáp án của bạn: ");
    
    userAnswer = getUserAnswer();

    if (userAnswer == q.correctAnswer) {
        *score += 10;
        printf("🎉 Đúng rồi! Điểm hiện tại: %d\n", *score);
    } else {
        printf("❌ Sai rồi! Đáp án đúng là: %c. %s\n", q.correctAnswer, q.options[q.correctAnswer - 'a']);
    }
}

int main() {
    int score = 0;
    char playerName[100];
    
    printf("Nhập tên của bạn: ");
    scanf("%[^\n]", playerName);
    getchar();
    
    Question questions[TOTAL_QUESTIONS] = {
        {"THE HOLY LAND là gì?", {"Jerusalem", "Mathura", "Mecca"}, 'a'},
        {"THE ROOF OF THE WORLD là gì?", {"Nepal", "Rome", "Tibet"}, 'c'},
        {"THE LAND OF RISING SUN là gì?", {"Chicago", "Japan", "Tibet"}, 'b'},
        {"THE GIFT OF NILE là gì?", {"Chicago", "Egypt", "Africa"}, 'b'},
        {"THE LAND OF MIDNIGHT SUN là gì?", {"Norway", "Japan", "Australia"}, 'a'},
        {"THE LAND OF THUNDERBOLT là gì?", {"Bhutan", "Canada", "Arab"}, 'a'},
        {"THE WINDY CITY là gì?", {"Jerusalem", "Japan", "Chicago"}, 'c'},
        {"THE LAND OF WHITE ELEPHANTS là gì?", {"Bangladesh", "Thailand", "India"}, 'b'},
        {"THE CITY OF SEVEN HILLS là gì?", {"Rome", "Nilgiri Hills", "Tibet"}, 'a'},
        {"THE DARK CONTINENT là gì?", {"Asia", "Australia", "Africa"}, 'c'}
    };

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        system("cls"); // Windows, nếu Linux thì dùng system("clear");
        askQuestion(questions[i], &score);
        getchar();
    }

    system("cls");
    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);
    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);    printf("\n🎯 KẾT QUẢ 🎯\n");
    printf("Tên người chơi: %s\n", playerName);
    printf("Điểm tổng: %d/%d\n", score, TOTAL_QUESTIONS * 10);
    printf("Bạn trả lời đúng %d/%d câu (%.2f%%)\n", score / 10, TOTAL_QUESTIONS, (float)score / (TOTAL_QUESTIONS * 10) * 100);
    saveResult(playerName, score);

    char replay;
    printf("\nBạn có muốn chơi lại không? (y/n): ");
    scanf(" %c", &replay);
    if (tolower(replay) == 'y') {
        system("cls");
        main();
    } else {
        printf("Cảm ơn bạn đã chơi! 🎉\n");
    }

    return 0;
}
