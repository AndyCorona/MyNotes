package chatter.web;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class ForwardAndRedirectController {

    @RequestMapping("/view")
    public String toView() {
        //转发到 forwardAndRedirect 视图
        return "forwardAndRedirect";
    }

    @RequestMapping("/forward")
    public String forward() {
        //转发到 /view 路径
        return "forward:/view";
    }

    @RequestMapping("/redirect")
    public String redirect() {
        //重定向至 /view 路径
        return "redirect:/view";
    }
}
