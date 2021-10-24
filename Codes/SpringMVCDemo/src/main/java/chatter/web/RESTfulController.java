package chatter.web;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
public class RESTfulController {

    @GetMapping("/restful/user/{id}")
    public String get(@PathVariable String id) {
        System.out.println("获取成功");
        return "restful";
    }

    @PostMapping("/restful/user")
    public String post(String username, String userid) {
        System.out.println("修改成功");
        return "success";
    }

    @PutMapping("/restful/user")
    public String put() {
        System.out.println("更新成功");
        return "success";
    }

    @DeleteMapping("restful/user")
    public String delete() {
        System.out.println("删除成功");
        return "success";
    }
}
