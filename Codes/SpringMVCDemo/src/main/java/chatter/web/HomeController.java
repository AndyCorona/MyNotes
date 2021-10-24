package chatter.web;

import chatter.data.User;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HomeController {
    @RequestMapping("/")
    public String home() {
//        System.out.println(10 / 0);
        return "home";
    }

    @ExceptionHandler(value = {ArithmeticException.class})
    public String error(Exception exception, Model model) {

        model.addAttribute("mathException", exception);
        return "error";
    }
}
