package chatter.web;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.SessionAttribute;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.Map;

@SessionAttributes(value = "smsg")
@Controller
public class ScopeController {
//    @RequestMapping("/scopes")
//    public String RequestScope(HttpServletRequest request) {
//        request.setAttribute("msg","这是请求范围中的共享数据");
//        return "scopes";
//    }
//
//        @RequestMapping("/scopes")
//    public ModelAndView RequestScope() {
//        ModelAndView mav = new ModelAndView();
//        //共享数据存放到请求范围中
//        mav.addObject("msg", "这是请求范围中的共享数据");
//        //设置转发的视图名
//        mav.setViewName("scopes");
//        return mav;
//    }
//    @RequestMapping("/scopes")
//    public String RequestScope(Model model) {
//        model.addAttribute("msg", "这是请求范围中的共享数据");
//        return "scopes";
//    }
//    @RequestMapping("/scopes")
//    public String RequestScope(Map<String,Object> map) {
//        map.put("msg", "这是请求范围中的共享数据");
//        return "scopes";
//    }
//    @RequestMapping("/scopes")
//    public String RequestScope(ModelMap modelMap) {
//        modelMap.addAttribute("msg", "这是请求范围中的共享数据");
//        return "scopes";
//    }
//
//        @RequestMapping("/scopes")
//    public String SessionScopes(HttpSession session) {
//        session.setAttribute("smsg", "这是会话范围中的共享数据");
//        return "scopes";
//    }

    @RequestMapping("/scopes")
    public String ApplicationScopes(HttpServletRequest request) {
        ServletContext servletContext = request.getServletContext();
        servletContext.setAttribute("amsg", "这是应用范围中的共享数据");
        return "scopes";
    }
}
