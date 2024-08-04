#include "randomchangesgenerator.h"
#include <QRandomGenerator>

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

ChangeType RandomChangesGenerator::changePrice() {
    int changeDirection = QRandomGenerator::global()->bounded(Increase, Decrease + 1);
    return ChangeType(changeDirection);
}
