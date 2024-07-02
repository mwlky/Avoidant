#include "Math.h"
namespace Engine{
    Math::Math() {

    }

    int Math::GenerateNumber(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(min, max);
        int random = distrib(gen);

        return random;
    }

    float Math::GenerateNumber(float min, float max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(min, max);

        return dis(gen);
    }

}


