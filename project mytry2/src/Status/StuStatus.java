package Status;

public class StuStatus {
    private Integer id;
    private String name;
    private String sex;
    private String homeadress;
    private String telephone;
    
    

    public StuStatus(Integer id,String name,String sex,String homeadress,String telephone){
        super();
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.homeadress = homeadress;
        this.telephone = telephone;
        
    }

    public StuStatus() {

    }

    //声明方法  在这里可以使用快捷键：Alt+Insert 
    //调出Generate 点击Getter and Setter 选择所有变量自动批量插入声明方法
    
    public Integer getId() {return id;}
    public String getName() { return name; }
    public String getSex() {return sex; }
    public String getHomeadress() {return homeadress; }
    public String getTelephone() {return telephone; }    

    public void  setId(int id) {this.id = id;}
    public void  setName(String name) { this.name = name; }
    public void  setSex(String sex) {this.sex = sex; }
    public void  setHomeadress(String homeadress) {this.homeadress = homeadress; }
    public void  setTelephone(String telephone) {this.telephone = telephone; }
}

