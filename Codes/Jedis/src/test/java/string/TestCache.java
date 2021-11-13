package string;

import org.junit.jupiter.api.Test;
import string.Cache;

public class TestCache {

    @Test
    public void testCache() {
        //创建 Redis 对象
        Cache.getJedis();

        //创建缓存对象
        Cache cache = new Cache();

        //创建缓存
        cache.set("key1", "value1");

        //查询缓存 value
        String value1 = cache.get("key1");

        //查询空的缓存 value
        String value2 = cache.get("key2");

        //key1-value1, key2-null
        assert "value1".equals(value1);
        assert value2 == null;

        //更新 key1 的缓存 value，返回旧 value
        String updated = cache.update("key1", "newValue");
        String newValue = cache.get("key1");

        //key1-newValue，旧 value 为 value1
        assert ("value1").equals(updated);
        assert ("newValue").equals(newValue);
    }
}
