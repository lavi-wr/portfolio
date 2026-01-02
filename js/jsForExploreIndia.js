 function handlesubmit() {
alert("Thank you for registering! We will get back to you soon.");
return false;
            }
   

   function changeColor() {
  const heading = document.getElementById("mainHeading");
  heading.style.color = heading.style.color === "green" ? "white" : "green";
}


    function calculateTripCost() {
      const days = prompt(" How many days will you travel?");
      const daily = prompt(" What’s your estimated daily budget in ₹?");
      
      if (isNaN(days) || isNaN(daily) || days <= 0 || daily <= 0) {
        alert("Please enter valid positive numbers.");
        return;
      }

      const travelType = prompt("Choose travel type: Budget / Standard / Luxury").toLowerCase();
      let multiplier = 1;

      if (travelType === "luxury") multiplier = 1.5;
      else if (travelType === "standard") multiplier = 1.2;
      else if (travelType === "budget") multiplier = 1;
      else {
        alert(" Invalid travel type. Defaulting to Standard.");
        multiplier = 1.2;
      }

      const includeTransport = confirm(" Include ₹3000 transport fare?");
      const transportCost = includeTransport ? 3000 : 0;

      const baseCost = parseFloat(daily) * parseInt(days) * multiplier;
      const gst = 0.05 * baseCost;
      const total = baseCost + gst + transportCost;

      alert(` Your estimated trip cost is ₹${total.toFixed(2)}\n(Based on ${days} days, ${travelType} travel, GST + optional transport)`);
    }