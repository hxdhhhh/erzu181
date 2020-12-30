package Status;

public class stuGrade {
	 private Integer id ;
	 private String name;
     private Integer Chinese;
     private Integer Math;
     private Integer English;
     private Integer sumgrade;
     private Integer avegrade;
     private Integer ranking;
	
	
	public stuGrade(Integer id, String name, Integer chinese, Integer math, Integer english) {
		super();
		this.id = id;
		this.name = name;
		Chinese = chinese;
		Math = math;
		English = english;
		this.sumgrade = chinese + math + english;
		this.avegrade = (chinese + math + english)/3;
	}
	public stuGrade() {
		
	}
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Integer getChinese() {
		return Chinese;
	}
	public void setChinese(Integer chinese) {
		Chinese = chinese;
	}
	public Integer getMath() {
		return Math;
	}
	public void setMath(Integer math) {
		Math = math;
	}
	public Integer getEnglish() {
		return English;
	}
	public void setEnglish(Integer english) {
		English = english;
	}
	public Integer getSumgrade() {
		return Chinese + Math + English ;
	}
	public Integer getAvegrade() {
		return (Chinese + Math + English)/3;
	}
	public Integer getRanking() {
		return ranking;
	}
	public void setRanking(Integer ranking) {
		this.ranking = ranking;
	}
	
}
