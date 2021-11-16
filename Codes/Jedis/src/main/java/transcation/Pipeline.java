package transcation;

import redis.clients.jedis.Jedis;

import java.util.List;

public class Pipeline {


    //流水线
    public static void main(String[] args) {

        //创建 Redis 对象
        Jedis jedis = new Jedis("192.168.159.130", 6379);

        //创建流水线对象
        redis.clients.jedis.Pipeline pipelined = jedis.pipelined();


        //加入多个命令
        pipelined.set("key1", "value1");
        pipelined.hset("hkey1", "hfield1", "hvalue1");
        pipelined.sadd("skey1", "mem1", "mem2", "mem3");

        //返回流水线执行后的结果
        List<Object> objects = pipelined.syncAndReturnAll();

        for(Object obj : objects){
            System.out.println(obj);
        }
    }

}
