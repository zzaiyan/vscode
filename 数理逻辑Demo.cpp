#include <bits/stdc++.h>
using namespace std;

struct HufNode
{
    double weight;
    int parent, left, right;
};

int main()
{
    int score;
    string grade;
    cin >> score;
    // 1.0
    if (score == 100)
        grade = "满分";
    else if (90 <= score && score < 100)
        grade = "优秀";
    else if (80 <= score && score < 90)
        grade = "良好";
    else if (70 <= score && score < 80)
        grade = "中等";
    else if (60 <= score && score < 70)
        grade = "及格";
    else if (0 <= score && score < 60)
        grade = "不及格";

    // 2.0
    if (80 <= score && score < 90)
        grade = "良好";
    else if (90 <= score && score < 100)
        grade = "优秀";
    else if (70 <= score && score < 80)
        grade = "中等";
    else if (60 <= score && score < 70)
        grade = "及格";
    else if (score == 100)
        grade = "满分";
    else if (0 <= score && score < 60)
        grade = "不及格";

    // 3.0
    if (80 <= score && score < 100)
    {
        if (score < 90)
            grade = "良好";
        else
            grade = "优秀";
    }
    else
    {
        if (70 <= score && score < 80)
            grade = "中等";
        else if (60 <= score && score < 70)
            grade = "及格";
        else if (score == 100)
            grade = "满分";
        else
            grade = "不及格";
    }

    // 3.0
    if (80 <= score && score < 100)
    {
        if (score < 90)
            grade = "良好";
        else
            grade = "优秀";
    }
    else
    {
        if (70 <= score && score < 80)
            grade = "中等";
        else if (60 <= score && score < 70)
            grade = "及格";
        else if (score == 100)
            grade = "满分";
        else
            grade = "不及格";
    }
}