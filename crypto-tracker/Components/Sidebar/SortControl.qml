import QtQuick 2.15
import CryptoColumnIndices 1.0

SortControlForm {
    signal sortCoins(index: int)

    rankingButton.onCheckedChanged: {
        if (rankingButton.checked) {
            sortCoins(CryptoColumnIndices.RankColumn)
        }
    }
    priceButton.onCheckedChanged: {
        if (priceButton.checked) {
            sortCoins(CryptoColumnIndices.PriceColumn)
        }
    }
    change24hButton.onCheckedChanged: {
        if (change24hButton.checked) {
            sortCoins(CryptoColumnIndices.PriceChangePercentage24hColumn)
        }
    }
    nameButton.onCheckedChanged: {
        if (nameButton.checked) {
            sortCoins(CryptoColumnIndices.NameColumn)
        }
    }
}
