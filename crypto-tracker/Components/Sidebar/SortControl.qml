import QtQuick 2.15
import CryptoColumnIndices 1.0

SortControlForm {
    signal sortCoins(index: int, order: int)

    rankingButton.onCheckedChanged: {
        if (rankingButton.checked) {
            sortCoins(CryptoColumnIndices.RankColumn, getSelectedOrder())
        }
    }
    priceButton.onCheckedChanged: {
        if (priceButton.checked) {
            sortCoins(CryptoColumnIndices.PriceColumn, getSelectedOrder())
        }
    }
    change24hButton.onCheckedChanged: {
        if (change24hButton.checked) {
            sortCoins(CryptoColumnIndices.PriceChangePercentage24hColumn, getSelectedOrder())
        }
    }
    nameButton.onCheckedChanged: {
        if (nameButton.checked) {
            sortCoins(CryptoColumnIndices.NameColumn, getSelectedOrder())
        }
    }
    ascendingButton.onCheckedChanged: {
        if (ascendingButton.checked) {
            sortCoins(getSelectedButtonIndex(), Qt.AscendingOrder)
        }
    }
    descendingButton.onCheckedChanged: {
        if (descendingButton.checked) {
            sortCoins(getSelectedButtonIndex(), Qt.DescendingOrder)
        }
    }

    function getSelectedButtonIndex() {
        if (rankingButton.checked) return CryptoColumnIndices.RankColumn;
        if (priceButton.checked) return CryptoColumnIndices.PriceColumn;
        if (change24hButton.checked) return CryptoColumnIndices.PriceChangePercentage24hColumn;
        return CryptoColumnIndices.NameColumn;
    }

    function getSelectedOrder() {
        if (ascendingButton.checked) return Qt.AscendingOrder;
        return Qt.DescendingOrder;
    }
}
