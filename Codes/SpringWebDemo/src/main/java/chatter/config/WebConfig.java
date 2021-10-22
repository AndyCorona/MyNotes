package chatter.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.ViewResolver;
import org.springframework.web.servlet.config.annotation.DefaultServletHandlerConfigurer;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurerAdapter;
import org.springframework.web.servlet.view.InternalResourceViewResolver;
import org.springframework.web.servlet.view.UrlBasedViewResolver;
import org.thymeleaf.cache.StandardCacheManager;
import org.thymeleaf.spring5.SpringTemplateEngine;
import org.thymeleaf.spring5.templateresolver.SpringResourceTemplateResolver;
import org.thymeleaf.spring5.view.ThymeleafViewResolver;
import org.thymeleaf.templatemode.TemplateMode;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;
import org.thymeleaf.templateresolver.StringTemplateResolver;

import java.io.StringReader;

@Configuration
@EnableWebMvc
@ComponentScan("chatter.web")
public class WebConfig extends WebMvcConfigurerAdapter {

    //配置 JSP 视图解析器
//    @Bean
//    public ViewResolver viewResolver() {
//        UrlBasedViewResolver resolver = new UrlBasedViewResolver();
//        resolver.setPrefix("WEB-INF/views/");
//        resolver.setSuffix(".jsp");
//        resolver.setViewClass(InternalResourceViewResolver.class);
//        return resolver;
//
//    }

    //创建并配置模板解析器
    @Bean
    public SpringResourceTemplateResolver templateResolver() {
        //创建 SpringResourceTemplateResolver 对象
        SpringResourceTemplateResolver templateResolver = new SpringResourceTemplateResolver();
        templateResolver.setCharacterEncoding("UTF-8");
        //设置模板模式
        templateResolver.setTemplateMode(TemplateMode.HTML);
        //设置前缀
        templateResolver.setPrefix("WEB-INF/classes/templates/");
        //设置后缀
        templateResolver.setSuffix(".html");

        return templateResolver;
    }

    //创建并配置模板引擎
    @Bean
    public SpringTemplateEngine templateEngine(SpringResourceTemplateResolver templateResolver) {

        //创建 SpringTemplateEngine 对象
        SpringTemplateEngine templateEngine = new SpringTemplateEngine();

        //传入模板解析器
        templateEngine.setTemplateResolver(templateResolver);
        StandardCacheManager cacheManager = new StandardCacheManager();

        return templateEngine;
    }

    //创建 Thymeleaf 视图解析器
    @Bean
    public ThymeleafViewResolver resolver(SpringTemplateEngine springTemplateEngine) {
        ThymeleafViewResolver resolver = new ThymeleafViewResolver();
        resolver.setTemplateEngine(springTemplateEngine);
        resolver.setCharacterEncoding("UTF-8");
        return resolver;
    }

    //配置静态资源处理
    @Override
    public void configureDefaultServletHandling(DefaultServletHandlerConfigurer configurer) {
        configurer.enable();
    }


}
