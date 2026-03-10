import { useState } from "react";

const translations = {
  th: {
    title: "BMI & BMR",
    subtitle: "คำนวณดัชนีมวลกายและอัตราเผาผลาญพื้นฐาน",
    gender: "เพศ",
    male: "ชาย",
    female: "หญิง",
    age: "อายุ",
    years: "ปี",
    height: "ส่วนสูง",
    cm: "ซม.",
    weight: "น้ำหนัก",
    kg: "กก.",
    calculate: "คำนวณ",
    reset: "รีเซ็ต",
    yourBMI: "BMI ของคุณ",
    yourBMR: "BMR ของคุณ",
    calDay: "แคล/วัน",
    bmiStatus: "สถานะ",
    underweight: "น้ำหนักต่ำกว่าเกณฑ์",
    normal: "น้ำหนักปกติ",
    overweight: "น้ำหนักเกิน",
    obese: "โรคอ้วน",
    bmiNote: "BMI = น้ำหนัก(กก.) ÷ ส่วนสูง(ม.)²",
    bmrNote: "BMR คือพลังงานที่ร่างกายต้องการในการพักผ่อน",
    lang: "EN",
  },
  en: {
    title: "BMI & BMR",
    subtitle: "Body Mass Index & Basal Metabolic Rate",
    gender: "Gender",
    male: "Male",
    female: "Female",
    age: "Age",
    years: "yrs",
    height: "Height",
    cm: "cm",
    weight: "Weight",
    kg: "kg",
    calculate: "Calculate",
    reset: "Reset",
    yourBMI: "Your BMI",
    yourBMR: "Your BMR",
    calDay: "kcal/day",
    bmiStatus: "Status",
    underweight: "Underweight",
    normal: "Normal",
    overweight: "Overweight",
    obese: "Obese",
    bmiNote: "BMI = weight(kg) ÷ height(m)²",
    bmrNote: "BMR = calories your body needs at rest",
    lang: "ไทย",
  },
};

function getBMICategory(bmi, t) {
  if (bmi < 18.5) return { label: t.underweight, color: "#60a5fa", bg: "rgba(96,165,250,0.15)", bar: 20 };
  if (bmi < 25) return { label: t.normal, color: "#34d399", bg: "rgba(52,211,153,0.15)", bar: 50 };
  if (bmi < 30) return { label: t.overweight, color: "#fbbf24", bg: "rgba(251,191,36,0.15)", bar: 75 };
  return { label: t.obese, color: "#f87171", bg: "rgba(248,113,113,0.15)", bar: 95 };
}

export default function App() {
  const [lang, setLang] = useState("th");
  const t = translations[lang];

  const [form, setForm] = useState({ gender: "male", age: "", height: "", weight: "" });
  const [result, setResult] = useState(null);
  const [animated, setAnimated] = useState(false);

  const handleChange = (e) => setForm({ ...form, [e.target.name]: e.target.value });

  const calculate = () => {
    const age = parseFloat(form.age);
    const height = parseFloat(form.height);
    const weight = parseFloat(form.weight);
    if (!age || !height || !weight || age <= 0 || height <= 0 || weight <= 0) return;

    const h = height / 100;
    const bmi = weight / (h * h);
    let bmr;
    if (form.gender === "male") {
      bmr = 88.362 + 13.397 * weight + 4.799 * height - 5.677 * age;
    } else {
      bmr = 447.593 + 9.247 * weight + 3.098 * height - 4.33 * age;
    }
    setAnimated(false);
    setTimeout(() => {
      setResult({ bmi: bmi.toFixed(1), bmr: Math.round(bmr) });
      setAnimated(true);
    }, 50);
  };

  const reset = () => {
    setForm({ gender: "male", age: "", height: "", weight: "" });
    setResult(null);
    setAnimated(false);
  };

  const cat = result ? getBMICategory(parseFloat(result.bmi), t) : null;

  return (
    <div style={{
      minHeight: "100vh",
      background: "linear-gradient(135deg, #0f0c29 0%, #302b63 50%, #24243e 100%)",
      fontFamily: "'Sarabun', 'Segoe UI', sans-serif",
      display: "flex",
      alignItems: "center",
      justifyContent: "center",
      padding: "2rem 1rem",
      position: "relative",
      overflow: "hidden",
    }}>
      {/* Floating orbs */}
      <div style={{ position:"fixed", top:"-80px", left:"-80px", width:"320px", height:"320px", borderRadius:"50%", background:"radial-gradient(circle, rgba(139,92,246,0.25) 0%, transparent 70%)", pointerEvents:"none" }} />
      <div style={{ position:"fixed", bottom:"-100px", right:"-60px", width:"400px", height:"400px", borderRadius:"50%", background:"radial-gradient(circle, rgba(59,130,246,0.2) 0%, transparent 70%)", pointerEvents:"none" }} />

      <div style={{ width:"100%", maxWidth:"480px", position:"relative", zIndex:1 }}>

        {/* Lang toggle */}
        <div style={{ display:"flex", justifyContent:"flex-end", marginBottom:"1rem" }}>
          <button onClick={() => setLang(lang === "th" ? "en" : "th")} style={{
            background:"rgba(255,255,255,0.08)", border:"1px solid rgba(255,255,255,0.15)",
            color:"#e2e8f0", padding:"0.35rem 1rem", borderRadius:"999px",
            cursor:"pointer", fontSize:"0.85rem", fontFamily:"inherit", backdropFilter:"blur(8px)",
            transition:"all 0.2s",
          }}>{t.lang}</button>
        </div>

        {/* Header */}
        <div style={{ textAlign:"center", marginBottom:"2rem" }}>
          <h1 style={{
            fontSize:"3.5rem", fontWeight:"800", letterSpacing:"-2px",
            background:"linear-gradient(90deg, #a78bfa, #60a5fa, #34d399)",
            WebkitBackgroundClip:"text", WebkitTextFillColor:"transparent",
            margin:0, lineHeight:1,
          }}>{t.title}</h1>
          <p style={{ color:"rgba(200,200,230,0.6)", marginTop:"0.5rem", fontSize:"0.9rem" }}>{t.subtitle}</p>
        </div>

        {/* Card */}
        <div style={{
          background:"rgba(255,255,255,0.05)", backdropFilter:"blur(20px)",
          border:"1px solid rgba(255,255,255,0.1)", borderRadius:"24px",
          padding:"2rem", boxShadow:"0 25px 50px rgba(0,0,0,0.4)",
        }}>
          {/* Gender */}
          <div style={{ marginBottom:"1.5rem" }}>
            <label style={{ color:"rgba(200,200,230,0.7)", fontSize:"0.8rem", letterSpacing:"0.1em", textTransform:"uppercase", display:"block", marginBottom:"0.6rem" }}>{t.gender}</label>
            <div style={{ display:"grid", gridTemplateColumns:"1fr 1fr", gap:"0.75rem" }}>
              {["male","female"].map(g => (
                <button key={g} onClick={() => setForm({...form, gender:g})} style={{
                  padding:"0.75rem", borderRadius:"12px", cursor:"pointer", fontFamily:"inherit",
                  fontSize:"1rem", fontWeight:600, transition:"all 0.2s",
                  background: form.gender===g ? "linear-gradient(135deg,#7c3aed,#3b82f6)" : "rgba(255,255,255,0.05)",
                  border: form.gender===g ? "1px solid rgba(139,92,246,0.5)" : "1px solid rgba(255,255,255,0.1)",
                  color: form.gender===g ? "#fff" : "rgba(200,200,230,0.6)",
                  boxShadow: form.gender===g ? "0 4px 15px rgba(124,58,237,0.4)" : "none",
                }}>
                  {g === "male" ? "♂ " : "♀ "}{g === "male" ? t.male : t.female}
                </button>
              ))}
            </div>
          </div>

          {/* Inputs */}
          {[
            { name:"age", label:t.age, unit:t.years, placeholder:"25" },
            { name:"height", label:t.height, unit:t.cm, placeholder:"170" },
            { name:"weight", label:t.weight, unit:t.kg, placeholder:"65" },
          ].map(field => (
            <div key={field.name} style={{ marginBottom:"1.25rem" }}>
              <label style={{ color:"rgba(200,200,230,0.7)", fontSize:"0.8rem", letterSpacing:"0.1em", textTransform:"uppercase", display:"block", marginBottom:"0.5rem" }}>{field.label}</label>
              <div style={{ position:"relative" }}>
                <input
                  type="number" name={field.name} value={form[field.name]}
                  onChange={handleChange} placeholder={field.placeholder}
                  style={{
                    width:"100%", padding:"0.85rem 3.5rem 0.85rem 1rem",
                    background:"rgba(255,255,255,0.07)", border:"1px solid rgba(255,255,255,0.12)",
                    borderRadius:"12px", color:"#e2e8f0", fontSize:"1.1rem", fontFamily:"inherit",
                    outline:"none", boxSizing:"border-box", transition:"border 0.2s",
                  }}
                  onFocus={e => e.target.style.border="1px solid rgba(139,92,246,0.6)"}
                  onBlur={e => e.target.style.border="1px solid rgba(255,255,255,0.12)"}
                />
                <span style={{ position:"absolute", right:"1rem", top:"50%", transform:"translateY(-50%)", color:"rgba(200,200,230,0.45)", fontSize:"0.85rem" }}>{field.unit}</span>
              </div>
            </div>
          ))}

          {/* Buttons */}
          <div style={{ display:"grid", gridTemplateColumns:"1fr auto", gap:"0.75rem", marginTop:"1.75rem" }}>
            <button onClick={calculate} style={{
              padding:"1rem", borderRadius:"14px", cursor:"pointer", fontFamily:"inherit",
              fontSize:"1rem", fontWeight:"700", border:"none", letterSpacing:"0.05em",
              background:"linear-gradient(135deg, #7c3aed, #3b82f6)",
              color:"#fff", boxShadow:"0 8px 25px rgba(124,58,237,0.45)",
              transition:"all 0.2s", transform:"translateY(0)",
            }}
              onMouseEnter={e => { e.target.style.transform="translateY(-2px)"; e.target.style.boxShadow="0 12px 30px rgba(124,58,237,0.6)"; }}
              onMouseLeave={e => { e.target.style.transform="translateY(0)"; e.target.style.boxShadow="0 8px 25px rgba(124,58,237,0.45)"; }}
            >{t.calculate}</button>
            <button onClick={reset} style={{
              padding:"1rem 1.25rem", borderRadius:"14px", cursor:"pointer", fontFamily:"inherit",
              fontSize:"1rem", fontWeight:"600", background:"rgba(255,255,255,0.07)",
              border:"1px solid rgba(255,255,255,0.1)", color:"rgba(200,200,230,0.6)",
              transition:"all 0.2s",
            }}>{t.reset}</button>
          </div>
        </div>

        {/* Result */}
        {result && (
          <div style={{
            marginTop:"1.5rem", display:"grid", gridTemplateColumns:"1fr 1fr", gap:"1rem",
            opacity: animated ? 1 : 0, transform: animated ? "translateY(0)" : "translateY(20px)",
            transition:"all 0.5s cubic-bezier(0.34,1.56,0.64,1)",
          }}>
            {/* BMI Card */}
            <div style={{
              background: cat.bg, backdropFilter:"blur(20px)",
              border:`1px solid ${cat.color}40`, borderRadius:"20px", padding:"1.5rem",
              boxShadow:`0 10px 30px ${cat.color}20`,
            }}>
              <div style={{ color:"rgba(200,200,230,0.6)", fontSize:"0.75rem", letterSpacing:"0.1em", textTransform:"uppercase", marginBottom:"0.5rem" }}>{t.yourBMI}</div>
              <div style={{ fontSize:"3rem", fontWeight:"800", color: cat.color, lineHeight:1 }}>{result.bmi}</div>
              <div style={{ marginTop:"0.75rem" }}>
                <div style={{ height:"4px", background:"rgba(255,255,255,0.1)", borderRadius:"99px", overflow:"hidden" }}>
                  <div style={{ height:"100%", width:`${cat.bar}%`, background:cat.color, borderRadius:"99px", transition:"width 0.8s ease" }} />
                </div>
              </div>
              <div style={{ marginTop:"0.6rem", fontSize:"0.85rem", fontWeight:"600", color: cat.color }}>{cat.label}</div>
              <div style={{ marginTop:"0.5rem", fontSize:"0.7rem", color:"rgba(200,200,230,0.4)", lineHeight:1.4 }}>{t.bmiNote}</div>
            </div>

            {/* BMR Card */}
            <div style={{
              background:"rgba(52,211,153,0.08)", backdropFilter:"blur(20px)",
              border:"1px solid rgba(52,211,153,0.25)", borderRadius:"20px", padding:"1.5rem",
              boxShadow:"0 10px 30px rgba(52,211,153,0.1)",
            }}>
              <div style={{ color:"rgba(200,200,230,0.6)", fontSize:"0.75rem", letterSpacing:"0.1em", textTransform:"uppercase", marginBottom:"0.5rem" }}>{t.yourBMR}</div>
              <div style={{ fontSize:"2.4rem", fontWeight:"800", color:"#34d399", lineHeight:1 }}>{result.bmr}</div>
              <div style={{ marginTop:"0.4rem", fontSize:"0.8rem", color:"rgba(52,211,153,0.7)" }}>{t.calDay}</div>
              <div style={{ marginTop:"0.75rem" }}>
                <div style={{ height:"4px", background:"rgba(255,255,255,0.1)", borderRadius:"99px", overflow:"hidden" }}>
                  <div style={{ height:"100%", width:"65%", background:"linear-gradient(90deg,#34d399,#60a5fa)", borderRadius:"99px", transition:"width 0.8s ease" }} />
                </div>
              </div>
              <div style={{ marginTop:"0.5rem", fontSize:"0.7rem", color:"rgba(200,200,230,0.4)", lineHeight:1.4 }}>{t.bmrNote}</div>
            </div>
          </div>
        )}

        {/* Footer */}
        <p style={{ textAlign:"center", color:"rgba(200,200,230,0.25)", fontSize:"0.72rem", marginTop:"2rem", letterSpacing:"0.05em" }}>
          Harris-Benedict Equation · Mifflin-St Jeor
        </p>
      </div>

      <style>{`
        input[type=number]::-webkit-inner-spin-button,
        input[type=number]::-webkit-outer-spin-button { -webkit-appearance: none; margin: 0; }
        input[type=number] { -moz-appearance: textfield; }
        * { box-sizing: border-box; }
      `}</style>
    </div>
  );
}