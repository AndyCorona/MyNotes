<%@ page contentType="text/html;charset=UTF-8" %>
<%@ include file="common.jsp" %>
<jsp:useBean id="cart" scope="session" class="com.likezhen.bookstore.ShoppingCart"/>
<html>
<head><title>Title</title></head>
<%@ include file="banner.jsp" %>
<p>
    您一共购买了<%=cart.getNumberOfItems()%>本书
</p>
<p>您应该支付的金额为<%=cart.getTotal()%>元</p>

<form action="<%=request.getContextPath()%>/receipt.jsp" method="post">
    <table>
        <tr>
            <td>信用卡用户名</td>
            <td><input type="text" name="cardname" value=""></td>
        </tr>
        <tr>
            <td>信用卡账号</td>
            <td><input type="text" name="card"></td>
        </tr>
        <tr>
            <td><input type="submit" value="支付"></td>
        </tr>
    </table>
</form>
</body>
</html>
