package string;

import redis.clients.jedis.Jedis;

public class Cache {
    private static Jedis jedis;


    /**
     * 创建  Redis 连接对象
     */
    public static void getJedis() {
        jedis = new Jedis("192.168.159.130", 6379);
    }

    /**
     *
     * @param key 缓存的 key
     * @param value 缓存的 value
     */
    public void set(String key, String value) {
        jedis.set(key, value);
    }

    /**
     *
     * @param key 获取 key 对应的 value
     * @return 返回 value，若 value 不存在返回 null
     */
    public String get(String key) {
        return jedis.get(key);
    }

    /**
     *
     * @param key 要更新的 key
     * @param newValue 用于更新的新 value
     * @return 返回旧 value，若旧 value 不存在返回 null
     */
    public String update(String key, String newValue) {
        return jedis.getSet(key, newValue);
    }
}
