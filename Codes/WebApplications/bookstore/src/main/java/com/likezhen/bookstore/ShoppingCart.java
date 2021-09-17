package com.likezhen.bookstore;

import java.util.Collection;
import java.util.HashMap;

/**
 * 购物车类，由物品及其数量构成
 */
public class ShoppingCart {
    //存放购物车物品对象
    private HashMap<String, ShoppingCartItem> items = null;
    //购物车物品总数
    private int numberOfItems = 0;

    public ShoppingCart() {
        items = new HashMap<String, ShoppingCartItem>();
    }

    public synchronized void add(String bookId, BookDetails book) {
        //购物车里有该物品时
        if (items.containsKey(bookId)) {
            ShoppingCartItem cartItem = items.get(bookId);
            cartItem.incrementQuantity();
            //购物车里没有该物品时
        } else {
            ShoppingCartItem newItem = new ShoppingCartItem(book);
            items.put(bookId, newItem);
        }
        numberOfItems++;
    }

    public synchronized void remove(String bookId, BookDetails book) {
        if (items.containsKey(bookId)) {
            ShoppingCartItem cartItem = items.get(bookId);
            cartItem.decrementQuantity();

            if (cartItem.getQuantity() <= 0) {
                items.remove(bookId);
            }
            numberOfItems--;
        }
    }

    public synchronized Collection<ShoppingCartItem> getItems() {
        return items.values();
    }


    public synchronized double getTotal() {
        double amount = 0.0;

        for (ShoppingCartItem item : getItems()) {
            BookDetails book = (BookDetails) item.getItem();
            amount += item.getQuantity() * book.getPrice();
        }
        return Math.round(amount);
    }

    public synchronized void clear() {
        items.clear();
        numberOfItems = 0;
    }

    public int getNumberOfItems() {
        return numberOfItems;
    }
}
