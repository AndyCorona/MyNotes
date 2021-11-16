package transcation;

import redis.clients.jedis.Jedis;

public class Transaction {

    //事务
    public static void main(String[] args) {

        //创建 Redis 对象
        Jedis jedis = new Jedis("192.168.159.130", 6379);

        //创建事务对象
        redis.clients.jedis.Transaction transaction = jedis.multi();

        //添加事务
        transaction.mset("k1", "v1", "k2", "v2");
        transaction.del("k1");
        transaction.get("k2");

        //执行事务
        transaction.exec();

    }
}
