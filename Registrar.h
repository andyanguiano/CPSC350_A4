#include <iostream>

using namespace std;

class Registrar{
  public:
    Registrar();
    ~Registrar();

    bool checkIsBusy();
    void reset();

    int getIdleTime();
    int getLongestIdlee();
    void checkOver5();
    int getOver5();
    void checkLongestIdle();
    int getLongestIdle();
    int meanIdleTime();

  private:
    int idleTime;
    int over5;
    int longestIdle;
    int numberIdles;
    int totalIdleTime;
    float mean;
    bool isBusy;
};
