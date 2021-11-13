package string;

import redis.clients.jedis.Jedis;

public class Counter {

    /**
     * 创建 Redis 对象，初始化计数器 counter-0
     *
     * @return Redis 连接对象
     */
    public static Jedis getRedis() {
        Jedis jedis = new Jedis("192.168.159.130", 6379);
        jedis.set("counter", "0");
        return jedis;
    }

    /**
     * 计数器的值加一
     *
     * @param jedis
     */
    public void increase(Jedis jedis) {
        jedis.incr("counter");
    }

    /**
     * 计数器的值减一
     *
     * @param jedis
     */
    public void decrease(Jedis jedis) {
        jedis.decr("counter");
    }

    /**
     * @param jedis
     * @return 返回计数器的值，计数器不存在时返回 0
     */
    public int get(Jedis jedis) {

        String counter = jedis.get("counter");

        if (counter == null) {
            return 0;
        } else {
            return Integer.valueOf(counter);
        }
    }

    /**
     *
     * @param jedis
     * @return 返回计数器当前的值，值重置为 0
     */
    public int reset(Jedis jedis) {

        String counter = jedis.getSet("counter", "0");

        if ((jedis.get("counter") != null)) {
            return Integer.valueOf(counter);
        } else {
            return 0;
        }
    }
}
