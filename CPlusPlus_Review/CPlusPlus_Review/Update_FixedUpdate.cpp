#include <windows.h>
#include <iostream>

using namespace std;

class Game {
private:
    double m_frameCount = 0;
    double m_timeCount = 0;
    double m_fixedFrameCount = 0;
    double m_fixedTimeCount = 0;
    LARGE_INTEGER m_frequency;
    LARGE_INTEGER m_currentCount;
    LARGE_INTEGER m_prevCount;
    double m_deltaTime;
    const double m_fixedDeltaTime = 1.0 / 60.0;  // 60Hz�� FixedUpdate�� ����

public:
    Game() {
        QueryPerformanceFrequency(&m_frequency);
        QueryPerformanceCounter(&m_prevCount);
    }

    void Run() {
        double accumulatedTime = 0.0;

        while (true) {
            QueryPerformanceCounter(&m_currentCount);
            m_deltaTime = (m_currentCount.QuadPart - m_prevCount.QuadPart) / (double)m_frequency.QuadPart;
            m_prevCount = m_currentCount;

            accumulatedTime += m_deltaTime;

            while (accumulatedTime >= m_fixedDeltaTime) {
                FixedUpdate(m_fixedDeltaTime);
                accumulatedTime -= m_fixedDeltaTime;
            }

            Update(m_deltaTime);
        }
    }

    void Update(double deltaTime) {
        m_frameCount++;
        m_timeCount += deltaTime;

        if (m_timeCount >= 1.0) {
            double fps = m_frameCount / m_timeCount;
            //std::cout << "Update FPS: " << fps << std::endl;
            printf("Update FPS: %lf\n", fps);
            m_frameCount = 0;
            m_timeCount -= 1.0; // 1�� �̻� ������ �ð����� 1�ʸ� ���ش�
        }
    }

    void FixedUpdate(double fixedDeltaTime) {
        m_fixedFrameCount++;
        m_fixedTimeCount += fixedDeltaTime;

        if (m_fixedTimeCount >= 1.0) {
            double fps = m_fixedFrameCount / m_fixedTimeCount;
            std::cout << "Fixed Update FPS: " << fps << std::endl;
            m_fixedFrameCount = 0;
            m_fixedTimeCount -= 1.0; // 1�� �̻� ������ �ð����� 1�ʸ� ���ش�
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Game game;
    game.Run();

    return 0;
}