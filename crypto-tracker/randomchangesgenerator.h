#pragma once

#include <QObject>

class RandomChangesGenerator : public QObject {
    Q_OBJECT
public:
    RandomChangesGenerator(QObject *parent = nullptr);
    void makeRandomChanges(int startIndex, int endIndex);

private:
    int getRandomIndex(int startIndex, int endIndex, int excludedIndex = -1);
    float changePrice();

signals:
    void changeCryptoData(int index, float priceChange);
};
