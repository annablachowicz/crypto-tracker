#include "randomchangesgenerator.h"
#include <QRandomGenerator>

enum ChangeDirection {
    Increase,
    Decrease
};

RandomChangesGenerator::RandomChangesGenerator(QObject *parent)
    : QObject(parent) {}

void RandomChangesGenerator::makeRandomChanges(int startIndex, int endIndex) {
    int firstIndex = getRandomIndex(startIndex, endIndex);
    int secondIndex = getRandomIndex(startIndex, endIndex, firstIndex);

    emit changeCryptoData(firstIndex, changePrice());

    if (firstIndex != secondIndex) {
        emit changeCryptoData(secondIndex, changePrice());
    }
}

int RandomChangesGenerator::getRandomIndex(int startIndex, int endIndex, int excludedIndex) {
    if (startIndex != endIndex) {
        int randomIndex = excludedIndex;

        while (randomIndex == excludedIndex) {
            randomIndex = QRandomGenerator::global()->bounded(startIndex, endIndex + 1);
        }

        return randomIndex;
    } else {
        return startIndex;
    }
}

float RandomChangesGenerator::changePrice() {
    int changeDirection = QRandomGenerator::global()->bounded(Increase, Decrease);

    if (changeDirection == Increase) {
        return 2;
    } return - 2;
}
