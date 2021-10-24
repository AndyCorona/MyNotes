package chatter.config;

import chatter.web.myInterceptor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.CacheControl;
import org.springframework.web.multipart.commons.CommonsMultipartResolver;
import org.springframework.web.servlet.ViewResolver;
import org.springframework.web.servlet.config.annotation.*;
import org.springframework.web.servlet.handler.SimpleMappingExceptionResolver;
import org.springframework.web.servlet.i18n.LocaleChangeInterceptor;
import org.springframework.web.servlet.theme.ThemeChangeInterceptor;
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
import java.time.Duration;
import java.util.Map;
import java.util.Properties;

@Configuration
@EnableWebMvc
@ComponentScan("chatter.web")
public class WebConfig implements WebMvcConfigurer {

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

    //方式一：注册对静态资源的处理
    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry) {
        registry.addResourceHandler("/resources/**").addResourceLocations("classpath:/static/")
                .setCacheControl(CacheControl.maxAge(Duration.ofDays(365)));
    }

    //方式二：开启 Servlet 容器中的默认 Servlet
//    @Override
//    public void configureDefaultServletHandling(DefaultServletHandlerConfigurer configurer) {
//        //DispatcherServlet 无法处理的请求转发给默认 Servlet 处理
//        configurer.enable();
//    }


    //配置 id 名为 multipartResolver 的 CommonsMultipartResolver 实现文件上传
    @Bean("multipartResolver")
    public CommonsMultipartResolver multipartResolver() {
        CommonsMultipartResolver resolver = new CommonsMultipartResolver();
        resolver.setMaxUploadSize(20000);
        resolver.setDefaultEncoding("utf-8");
        return resolver;
    }

    //注册拦截器
    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        registry.addInterceptor(new myInterceptor()).addPathPatterns("/**").excludePathPatterns("/admin/**");
    }

    //配置 SimpleMappingExceptionResolver 对象
//    @Bean
//    public SimpleMappingExceptionResolver exceptionResolver() {
//        //创建 SimpleMappingExceptionResolver 对象
//        SimpleMappingExceptionResolver resolver = new SimpleMappingExceptionResolver();
//
//        Properties properties = new Properties();
//        //配置异常名和处理异常的视图名
//        properties.setProperty("java.lang.ArithmeticException", "error");
//        //映射异常名和视图名
//        resolver.setExceptionMappings(properties);
//        //设置共享在请求范围中的异常信息的属性名，默认为 exception
//        resolver.setExceptionAttribute("mathException");
//        return resolver;
//    }

}
