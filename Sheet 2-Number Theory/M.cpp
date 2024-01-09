// In recent times a very bad incident is happening repeatedly in Wonderland ((Poets
// Poets claim that she is the queen of all
// countries), questions of many public examination and admission tests are being
// leaked before the exam. The effect is less
// terrible when the exam involved is a written public exam, because still one has to
// go to exam halls and write things correctly. But if the exam involved has only
// MCQs (Multiple Choice Questions) the
// situation becomes grave — anyone who
// has a little bit of memorization power can
// get good marks if he gets MCQ questions
// with solution the day before the exam.
// For technical reasons and added expenditure, such an MCQ based exam cannot always be taken again. 
// So you are given the responsibility
// of detecting cheaters of such an MCQ based exam. The details of this exam and cheater detection
// process is given below:
// (a) There are at most 50000 MCQ questions in the exam
// (b) All questions have a difficulty, a status and a result associated with it. This difficulty is denoted
// with an integer d between 1 and 10 (Inclusive). The higher the value of d, the more difficult the
// question is. The status s can be either ‘1’ (The question was leaked) or ‘0’ (The question was not
// leaked). The result r is either ‘c’ (The answer given by the student is correct) or ‘i’ (The answer
// given by the student is incorrect). So a single MCQ question is denoted with two integers d, s
// and a character r.
// (c) A suspicious activity is counted when someone answers a leaked question with difficulty d1 correctly 
// but fails to answer a not leaked question with difficulty d2 correctly and (d1 > d2).
// (d) Given the description of questions in a set (including the correctness of each question for a
// particular examinee) your job is to write a program to find the total number of suspicious activities
// for that examinee.
// Input
// First line of the input file contains a positive integer T (T ≤ 80) which denotes the number of test
// cases. The description of each test case is given below:
// Each test case starts with a positive integer Q (1 ≤ Q ≤ 50000) which denotes the number of
// questions in the exam and each of the next Q lines describes 1 MCQ question. Each of the line contains
// two integers di (1 ≤ di ≤ 10), si and a character ri
// , here di denotes the difficulty, si denotes the status
// (‘1’ means it was leaked and ‘0’ means that it was not leaked) and ri denotes whether the examinee
// answered the question correctly (c) or incorrectly (i). In reality a day long MCQ exam does not have
// 50000 questions but this is just being given as input to test the efficiency of your algorithm as your
// program will be used to find cheaters among ten million students in a very short time.
// Output
// For each set of input produce one line of output. This line contains an integer which denotes the total
// number of suspicious activities for the given input.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int leaksCount;
        cin >> leaksCount;

        vector<int> leakedSolved;
        vector<int> notLeakedNotSolved;

        while (leaksCount--) {
            int difficulty, leaked;
            cin >> difficulty >> leaked;
            char solved;
            cin >> solved;

            if (leaked == 0 && solved == 'i') {
                notLeakedNotSolved.push_back(difficulty);
            }

            if (leaked == 1 && solved == 'c') {
                leakedSolved.push_back(difficulty);
            }
        }

        sort(notLeakedNotSolved.begin(), notLeakedNotSolved.end());

        long long result = 0;
        for (int i = 0; i < leakedSolved.size(); ++i) {
            if (notLeakedNotSolved.size() && notLeakedNotSolved[0] < leakedSolved[i]) {
                result += (upper_bound(notLeakedNotSolved.begin(), notLeakedNotSolved.end(), leakedSolved[i] - 1) - notLeakedNotSolved.begin());
            }
        }

        cout << result << endl;
    }

    return 0;
}