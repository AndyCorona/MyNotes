package hash;

import com.sun.org.apache.xpath.internal.operations.Bool;
import redis.clients.jedis.Jedis;

import java.net.ConnectException;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.NoSuchElementException;
import java.util.UUID;

public class LogSession {


    /**
     * 创建 Redis 对象
     *
     * @return Redis 连接对象
     */
    public static Jedis getRedis() {
        return new Jedis("192.168.159.130", 6379);
    }

    /**
     * 创建用户 Token
     *
     * @return 返回用户 Token
     * @throws NoSuchAlgorithmException
     */
    private String generateToken() throws NoSuchAlgorithmException {

        //用 sha-256 加密算法
        MessageDigest messageDigest = MessageDigest.getInstance("sha-256");

        //随机生成一个 UUID
        messageDigest.update((UUID.randomUUID()).toString().getBytes(StandardCharsets.UTF_8));

        //返回用户 Token
        return messageDigest.digest().toString();
    }

    /**
     * 根据用户 id，创建用户 Token
     *
     * @param jedis
     * @param timeout 过期时间
     * @param userId  用户 Id
     * @return
     */
    public String create(Jedis jedis, long timeout, String userId) {

        String userToken = null;

        try {

            //生成用户 Token
            userToken = generateToken();

            //放入 Redis 中，设置失效时间
            jedis.hset("userToken", userId, userToken);
            jedis.expire("userToken", timeout);

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            jedis.close();
            return userToken;
        }
    }


    /**
     * 判断用户 Token 是否有效
     *
     * @param jedis
     * @param userId
     * @return 失效返回 false
     */
    public Boolean validate(Jedis jedis, String userId) {
        return (jedis.hget("userToken", userId) == null) ? false : true;
    }
}
