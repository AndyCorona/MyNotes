package string;

import org.junit.jupiter.api.Test;
import redis.clients.jedis.Jedis;
import string.Counter;

public class TestCounter {
    @Test
    public void testCounter() {

        //获取 Redis 对象
        Jedis redis = Counter.getRedis();

        //获取计数器对象
        Counter counter = new Counter();

        //计数器初始化后值为 0
        assert counter.get(redis) == 0;

        //计数器值减一
        counter.decrease(redis);

        //计数器值为 -1
        assert counter.get(redis) == -1;

        //计数器增加10次
        for (int i = 0; i < 10; i++) {
            counter.increase(redis);
        }

        //计数器值为 9
        assert counter.get(redis) == 9;

        //清空计数器，返回计数器的值 9
        int value = counter.reset(redis);

        assert value == 9;

        redis.close();
    }
}
