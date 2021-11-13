package list;

import redis.clients.jedis.Jedis;

public class Quene {

    /**
     * 获取 Redis 对象
     * @return Redis 对象
     */
    public static Jedis getRedis() {
        return new Jedis("192.168.159.130", 6379);
    }

    /**
     * 入列
     * @param jedis
     * @param item 入列物品
     * @return 返列长度
     */
    public long enquene(Jedis jedis, String item) {
        jedis.lpush("quene", item);

        return jedis.llen("quene");
    }

    /**
     * 出列
     * @param jedis
     * @return 出列物品
     */
    public String dequene(Jedis jedis) {

        return jedis.rpop("quene");
    }

    public void enquene(String a) {
    }
}
