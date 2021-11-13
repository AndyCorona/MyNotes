package string;

import redis.clients.jedis.Jedis;
import redis.clients.jedis.params.SetParams;

public class Lock {

    /**
     * 创建 Redis 连接对象
     * @return 返回 Jedis 对象
     */
    public static Jedis getRedis() {
        return new Jedis("192.168.159.130", 6379);
    }

    /**
     *
     * @param jedis
     * @return 是否拿到锁
     */
    public boolean acquire(Jedis jedis) {

        //创建 lockKey-locked 键值对表示拿到锁
        return (jedis.set("lockKey", "locked", SetParams.setParams().nx()) == null) ? false : true;
    }

    /**
     *
     * @param jedis
     * @return 是否释放锁
     */
    public boolean release(Jedis jedis) {
        //删除 lockKey-locked 键值对表示释放锁
        return (jedis.del("lockKey") == 1) ? true : false;
    }
}
