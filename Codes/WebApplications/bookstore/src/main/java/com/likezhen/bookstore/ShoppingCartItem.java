package com.likezhen.bookstore;

/**
 * 购物车物品类，一个物品由一种图书及其数量构成
 */
public class ShoppingCartItem {
    private BookDetails item;
    private int quantity;

    public ShoppingCartItem() {
    }

    public ShoppingCartItem(BookDetails item) {
        this.item = item;
        quantity = 1;
    }

    public void incrementQuantity() {
        quantity++;
    }

    public void decrementQuantity() {
        quantity--;
    }

    public BookDetails getItem() {
        return item;
    }

    public int getQuantity() {
        return quantity;
    }
}
