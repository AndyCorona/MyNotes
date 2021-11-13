package string;

import org.junit.jupiter.api.Test;
import redis.clients.jedis.Jedis;
import string.Lock;

public class TestLock {

    @Test
    public void testLock() {

        //创建 redis 对象
        Jedis redis = Lock.getRedis();

        //获取锁对象1
        Lock lock = new Lock();

        //锁对象1获取锁
        boolean acquired = lock.acquire(redis);

        //锁对象1成功获取锁
        assert acquired == true;

        //获取锁对象2
        Lock lockAnother = new Lock();

        //锁对象2尝试获取锁
        boolean acquiredAnother = lockAnother.acquire(redis);

        //锁对象1锁未释放，此时锁对象2应该无法获取锁
        assert acquiredAnother == false;

        //锁对象1释放锁
        boolean released = lock.release(redis);
        //锁对象1锁释放成功
        assert released == true;

        //锁对象2再次获取锁
        boolean acquiredAgain = lockAnother.acquire(redis);

        //锁对象2获取成功
        assert acquiredAgain == true;

        //锁对象2释放锁
        lockAnother.release(redis);

        redis.close();
    }
}
