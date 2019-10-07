package com.billchen.spesislindt;

import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

@SuppressWarnings("unchecked")
public class BeanManager {

    public static Map beanContainer = new HashMap<Class, Object>();
    public static Logger logger = Logger.getLogger("BeanManager");

    public static <T> T getBean(Class clazz) {
        if (beanContainer.containsKey(clazz)) {
            return (T) beanContainer.get(clazz);
        } else {
            try {
                Object obj = clazz.getDeclaredConstructor().newInstance();
                beanContainer.put(clazz, obj);
                return (T) obj;
            } catch (Exception e) {
                logger.log(Level.WARNING, "Class instantiation failed.");
                return null;
            }
        }
    }

    public static void removeBean(Class clazz) {
        beanContainer.remove(clazz);
    }
}
