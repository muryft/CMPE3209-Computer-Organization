/* Yagmur Feyza Tuncer, SID: 1230029 (5001230029 son 9 hanesi), G2 */
#define N 28
#define R 101U
#define B 0U

const int SID = 1230029;
int grades[N];
int bucket[5] = {0, 0, 0, 0, 0};
int mean = 0;
int below_count = 0;
int pass_count = 0;

void generate_data(void);
void process_grades(void);
int calculate_mean(const int arr[], int size);

int main(void){
    generate_data();
    process_grades();
    return 0;
}

int calculate_mean(const int arr[], int size){
    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}

void generate_data(void){
    unsigned int x = (unsigned int)SID;

    for (int i = 0; i < N; i++) {
        x = 1664525U * x + 1013904223U;
        grades[i] = (int)(((x >> 16) % R) + B);
    }
}

void process_grades(void) {
    mean = calculate_mean(grades, N);
    int P = 50 + (SID % 10);

    for (int i = 0; i < N; i++) {
        int score = grades[i] & 0xFF;

        if (score < 50) bucket[0]++;
        else if (score < 65) bucket[1]++;
        else if (score < 75) bucket[2]++;
        else if (score < 85) bucket[3]++;
        else bucket[4]++;

        if (score >= P) pass_count++;
        if (score < mean) {
            below_count++;
            grades[i] = score | 0x100;
        }
    }
}