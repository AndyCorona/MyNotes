package chatter.web;

import chatter.data.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpServletRequest;

@Controller
public class ReqParamController {

//    使用 ServletRequest 对象获取查询参数
//    @RequestMapping("/params")
//    public String getReqParam(HttpServletRequest request) {
//        String id = request.getParameter("id");
//        String name = request.getParameter("name");
//        System.out.println("id = " + id + " name = " + name);
//        return "reqparam";
//    }

    //使用处理方法的形参获取同名查询参数
//    @RequestMapping("/params")
//    public String getReqParam(String id, String name) {
//        System.out.println("id = " + id + " name = " + name);
//        return "reqparam";
//    }

    //使用 @RequestParam 注解获取查询参数
//    @RequestMapping("/params")
//    public String getReqParam(@RequestParam(value = "userid", required = false) String id, @RequestParam("username") String name) {
//        System.out.println("id = " + id + " name = " + name);
//        return "reqparam";
//    }

    //使用 POJO 接收查询参数
    @RequestMapping("/params")
    public String getReqParam(User user) {
        System.out.println(user);
        return "reqparam";

    }

}
