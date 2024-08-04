#pragma once

#include <QObject>

enum ChangeType {
    Increase,
    Decrease
};

class RandomChangesGenerator : public QObject {
    Q_OBJECT
public:
    RandomChangesGenerator(QObject *parent = nullptr);
    void makeRandomChanges(int startIndex, int endIndex);

private:
    int getRandomIndex(int startIndex, int endIndex, int excludedIndex = -1);
    ChangeType changePrice();

signals:
    void changeCryptoData(int index, ChangeType changeType);
};
