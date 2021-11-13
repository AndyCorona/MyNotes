package list;

import org.junit.jupiter.api.Test;
import redis.clients.jedis.Jedis;

public class TestQuene {
    @Test
    public void testQuene() {

        long number = 0;

        Jedis redis = Quene.getRedis();

        Quene quene = new Quene();

        //入列 C->B->A
        quene.enquene(redis, "A");
        quene.enquene(redis, "B");
        number = quene.enquene(redis, "C");

        //队列元素个数
        assert (number == 3);

        String item = null;

        //出列顺序，先 A 在 B 后 C，符合先进先出
        item = quene.dequene(redis);

        assert "A".equals(item);

        item = quene.dequene(redis);

        assert "B".equals(item);

        item = quene.dequene(redis);

        assert "C".equals(item);
    }
}
