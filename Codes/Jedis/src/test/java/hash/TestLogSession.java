package hash;

import org.junit.jupiter.api.Test;
import redis.clients.jedis.Jedis;

public class TestLogSession {
    @Test
    public void testLogSession() throws Exception {


        Jedis redis = LogSession.getRedis();

        LogSession logSession = new LogSession();

        //获取用户令牌
        String token = logSession.create(redis, 10, "andy");

        //验证令牌有效性
        Boolean validation = logSession.validate(redis, "andy");

        //令牌有效期 10s，此时还有效
        assert validation == true;

        //等待 15s
        Thread.sleep(15000);

        //此时令牌失效
        validation = logSession.validate(redis, "andy");

        assert validation == false;
    }
}
