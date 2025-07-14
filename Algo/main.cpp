#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    // 시작시간과 끝시간을 초단위로 변환
    int startTime = h1 * 3600 + m1 * 60 + s1;
    int endTime = h2 * 3600 + m2 * 60 + s2;

    // 시작점이 00:00:00 또는 12:00:00일 때는 미리 카운팅
    if (startTime == 0 || startTime == 12 * 3600) {
        answer++;
    }

    while (startTime < endTime) {
        // 현재 각도 계산
        double hCurAngle = fmod((double)startTime / 120.0, 360.0);
        double mCurAngle = fmod((double)startTime / 10.0, 360.0);
        double sCurAngle = fmod((double)startTime * 6.0, 360.0);

        double hNextAngle = fmod((double)(startTime + 1) / 120.0, 360.0);
        double mNextAngle = fmod((double)(startTime + 1) / 10.0, 360.0);
        double sNextAngle = fmod((double)(startTime + 1) * 6.0, 360.0);

        if (hNextAngle == 0) hNextAngle = 360;
        if (mNextAngle == 0) mNextAngle = 360;
        if (sNextAngle == 0) sNextAngle = 360;

        if (sCurAngle < hCurAngle && sNextAngle >= hNextAngle)
            answer++;
        if (sCurAngle < mCurAngle && sNextAngle >= mNextAngle)
            answer++;
        if (fabs(sNextAngle - hNextAngle) < 1e-8 && fabs(hNextAngle - mNextAngle) < 1e-8)
            answer--;

        startTime++;
    }

    return answer;
}